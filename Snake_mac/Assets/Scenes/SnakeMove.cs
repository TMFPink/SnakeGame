using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class SnakeMove : MonoBehaviour
{

    //use to set up the position of snake
    private Vector2 _direction = Vector2.right;

    //sound effect
    public AudioSource eating_sound;
    public AudioSource levelup_sound;
    public AudioSource die_sound;
    public AudioSource background_music;

    //control snake head
    public SpriteRenderer headSpriteRenderer;


    //segment is snake body
    private List<Transform> _segments = new List<Transform>();

    //snake have 3 lives
    public int lives = 3;
    public GameObject heart1;
    public GameObject heart2;
    public GameObject heart3;

    //start game snake have 3 body
    public int initialSize = 3;
    public Transform segmentPrefab;

    //score and highscore var
    public float score;
    public float Highscore;

    // text display
    public TextMeshProUGUI scoreTxt;

    public TextMeshProUGUI HighScoreText;

    public TextMeshProUGUI GameOver_display;

    //button display
    public Button Retry;
    public Button MainMenu;


    //snake go to right at the start of the game
    public int way = 2;

    private SnakeMove player;

    private void Start()
    {
        //init first state
        ResetState();
        player = FindObjectOfType<SnakeMove>();

        // not display button and text
        Retry.gameObject.SetActive(false);
        MainMenu.gameObject.SetActive(false);
        GameOver_display.gameObject.SetActive(false);

    }

    //call every frame
    //frame is varialbe
    private void Update()
    {

        if (Input.GetKeyDown(KeyCode.W) || Input.GetKeyDown(KeyCode.UpArrow))
        {
            if (way != 3)
            {
                _direction = Vector2.up;
                way = 1;
                headSpriteRenderer.transform.rotation = Quaternion.Euler(0, 0, 0);
            }
        }
        else if (Input.GetKeyDown(KeyCode.S) || Input.GetKeyDown(KeyCode.DownArrow))
        {
            if (way != 1)
            {
                _direction = Vector2.down;
                way = 3;
                headSpriteRenderer.transform.rotation = Quaternion.Euler(0, 0, 180);
            }
        }
        else if (Input.GetKeyDown(KeyCode.A) || Input.GetKeyDown(KeyCode.LeftArrow))
        {
            if (way != 2)
            {
                _direction = Vector2.left;
                way = 4;
                headSpriteRenderer.transform.rotation = Quaternion.Euler(0, 0, 90);
            }
        }
        else if (Input.GetKeyDown(KeyCode.D) || Input.GetKeyDown(KeyCode.RightArrow))
        {
            if (way != 4)
            {
                _direction = Vector2.right;
                way = 2;
                headSpriteRenderer.transform.rotation = Quaternion.Euler(0, 0, -90);
            }
        }

        //display score
        scoreTxt.text = "" + score;

        //highscore
        UpdateHighScore();
        SaveHighScore();

    }

    //always run at fixed time interval (time step)
    private void FixedUpdate()
    {
        //new body is taking part of old body ( link list)
        for (int i = _segments.Count - 1; i > 0; i--)
        {
            _segments[i].position = _segments[i - 1].position;
        }
        //don't use z so set to zero
        this.transform.position = new Vector3(
            Mathf.Round(this.transform.position.x) + _direction.x,
            Mathf.Round(this.transform.position.y) + _direction.y,
            0.0f);
    }

    private void Grow()
    {
        //add body to snake
        Transform segment = Instantiate(this.segmentPrefab);
        segment.position = _segments[_segments.Count - 1].position;
        _segments.Add(segment);
    }
    private void ResetState()
    {


        //delete old body
        for (int i = 1; i < _segments.Count; i++)
        {
            Destroy(_segments[i].gameObject);
        }
        _segments.Clear();
        _segments.Add(this.transform);

        this.transform.position = Vector3.zero;

        //add new snake
        for (int i = 1; i < this.initialSize; i++)
        {
            _segments.Add(Instantiate(this.segmentPrefab));
        }
    }
    private void OnTriggerEnter2D(Collider2D other)
    {
        //if collide with food
        if (other.tag == "Food")
        {

            Grow();
            //eating music play
            eating_sound.Play();
            //increase score
            score++;

            //when hit 10 score
            if (score % 10 == 0)
            {
                //speacial sound 
                levelup_sound.Play();

                //snake speed is calculated by frame
                //By default, 0.06f (1/0.066=16.67 frames per second)
                //decline timestep mean increase frame => increase snake speed
                //timestep minus 0.01 frame
                Time.fixedDeltaTime -= 0.01f;
            }
        }
        //if collide with obstacle
        else if (other.tag == "Obstacle")
        {
            //lost live
            lives--;
            //check are there any remaining lives

            if (lives == 2)
            {
                heart3.SetActive(false);
                ResetState();
            }
            else if (lives == 1)
            {
                heart2.SetActive(false);
                ResetState();
            }
            else if (lives == 0)
            {
                heart1.SetActive(false);

                // Game over
                //reset time speed
                Time.fixedDeltaTime = 0.07f;
                //reset score
                score = 0;
                //stop background music
                background_music.Stop();
                //delete snake
                Destroy(gameObject);
                for (int i = 1; i < _segments.Count; i++)
                {
                    Destroy(_segments[i].gameObject);
                }

                //display button and text
                Retry.gameObject.SetActive(true);
                MainMenu.gameObject.SetActive(true);
                GameOver_display.gameObject.SetActive(true);
                //die music
                die_sound.Play();
                //reset lives;
                lives = 3;
            }

        }
    }

    public void SaveHighScore()
    {
        //if current score > old highscore then current score is highscore
        if (score > PlayerPrefs.GetFloat("HighScore", 0))
        {
            PlayerPrefs.SetFloat("HighScore", score);
            UpdateHighScore();
        }
    }
    void UpdateHighScore()
    {
        //update highscore
        HighScoreText.text = $"HighScore: {PlayerPrefs.GetFloat("HighScore", 0)}";
    }
}
