using UnityEngine;
using System.Collections;

public class Sound : MonoBehaviour
{

    public AudioClip audioClip;
    AudioSource audioSource;

    void Start()
    {
        audioSource = gameObject.GetComponent<AudioSource>();
        audioSource.clip = audioClip;
        audioSource.Play();
    }

 /*   void Update()
    {
        if (Input.GetKeyDown(KeyCode.A) == true)
        {
            
        }
    }*/
}