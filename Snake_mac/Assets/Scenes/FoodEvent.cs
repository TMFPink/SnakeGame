using UnityEngine;


public class FoodEvent : MonoBehaviour
{

    //var for area food can placed
    public BoxCollider2D gridArea;

    //place food at random position when start the game
    private void Start()
    {
        RandomPosition();
    }

    private void RandomPosition()
    {
        //food will be randomly place on area
        Bounds bounds = this.gridArea.bounds;

        float x = Random.Range(bounds.min.x, bounds.max.x);
        float y = Random.Range(bounds.min.y, bounds.max.y);

        this.transform.position = new Vector3(Mathf.Round(x), Mathf.Round(y), 0.0f);
    }
    private void OnTriggerEnter2D(Collider2D other)
    {
        //if collide with player then random to other position
        if (other.tag == "Player")
        {
            RandomPosition();
        }
    }
}
