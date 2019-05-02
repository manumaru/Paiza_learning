using UnityEngine;
using System.Collections;
using UnityEngine.UI;

/// <summary>
/// キーボードだけで操作できるようにSpaceキーでのSTARTを決めましたが、移動が遅いのでボタンのほうが正直早い 1度結果いったあとの2回目以降はちゃんとはやくなったのでこちらで
/// </summary>
public class Title : MonoBehaviour
{
    void Start()
    {
        //RoadRanking();
    }
    void OnGUI()
    {
        // ボタンを表示する →なしに
   /*     if( GUI.Button(new Rect(300, 180, 150, 50), "スタート")) //375migi300 300migi180
        {
            Debug.Log("Button is clicked.");
            Application.LoadLevel("CountDown");
        }
    */    
    }
    void Update()
    {
          if (Input.GetKeyDown(KeyCode.Space))
          {
              Application.LoadLevel("CountDown");
          }
    }


}
