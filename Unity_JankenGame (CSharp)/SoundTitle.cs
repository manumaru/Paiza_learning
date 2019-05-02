using UnityEngine;
using System.Collections;
/// <summary>
/// AudioSourceの増やし方がうまくいかなかったので1で1セリフ喋るだけ。2～6は飾り。
/// </summary>
public class SoundTitle : MonoBehaviour
{

    public AudioClip audioClip2;
    AudioSource audioSource2;
   /* public AudioClip audioClip3;
    AudioSource audioSource3;
    public AudioClip audioClip4;
    AudioSource audioSource4;
    public AudioClip audioClip5;
    AudioSource audioSource5;
    public AudioClip audioClip6;
    AudioSource audioSource6;*/

    void Start()
    {
        audioSource2 = gameObject.GetComponent<AudioSource>();
        audioSource2.clip = audioClip2;
/*        audioSource3 = gameObject.GetComponent<AudioSource>();
        audioSource3.clip = audioClip3;
        audioSource4 = gameObject.GetComponent<AudioSource>();
        audioSource4.clip = audioClip4;
        audioSource5 = gameObject.GetComponent<AudioSource>();
        audioSource5.clip = audioClip5;
        audioSource6 = gameObject.GetComponent<AudioSource>();
        audioSource6.clip = audioClip6;*/
    }

       void Update()
       {
           if (Input.GetKeyDown(KeyCode.Alpha1) == true)
           {
               audioSource2.Play();
           }
       /*    if (Input.GetKeyDown(KeyCode.Alpha2) == true)
           {
               audioSource3.Play();
           }
           if (Input.GetKeyDown(KeyCode.Alpha3) == true)
           {
               audioSource4.Play();
           }
           if (Input.GetKeyDown(KeyCode.Alpha4) == true)
           {
               audioSource5.Play();
           }
           if (Input.GetKeyDown(KeyCode.Alpha5) == true)
           {
               audioSource6.Play();
           }*/
       }
}

