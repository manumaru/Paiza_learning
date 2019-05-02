using UnityEngine;
using System.Collections;
using UnityEngine.UI;

/// <summary>
/// スペースキーでの移動を追加
/// </summary>

public class Result : MonoBehaviour 
{
    public Text CurrentScore;

    void Start()
    {
        if(Application.loadedLevelName == "WIN")
        {
        //Title.Rank1 = CountDownbattle.Score;
        }

    }

    void OnGUI()
    {
        var YourScore = "あなたの記録は  "+ CountDownbattle.Score.ToString() + "秒です。";
          //  Debug.Log(YourScore);                                                     ずっと出ちゃうので消した
           // GUI.Label(new Rect(390,240,150,50), YourScore);
            CurrentScore.text = YourScore;
        // ボタンを表示する
       /* if( GUI.Button(new Rect(320, 180, 150, 50), "STARTへ戻る"))	//375migi 320 300migi 180                                       if()内で宣言出来るのか！！かんどう
        {

            Debug.Log("Button is clicked.");                //ここは表示された。Titleへは飛ばなかった問題も    【解決】     →原因:Planeをコピーした際にデフォが0のJankenbattle.csが全てのシーンについていた。
            Application.LoadLevel("Title");
        
             
        }
        */

    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Application.LoadLevel("Title");
        }
    }

}

