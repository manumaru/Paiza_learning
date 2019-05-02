using UnityEngine;
using System.Collections;

/*      時間経過とともに背景の色調じょじょに変える奴考えたが今回はgive up      
        // 赤 -> 緑 -> 青 -> の順に変化させる
        IEnumerator ChangeCameraColor() {
            while (true) {
                yield return StartCoroutine(ChangeColor(Color.red, 1f));
                yield return StartCoroutine(ChangeColor(Color.green, 1f));
                yield return StartCoroutine(ChangeColor(Color.blue, 1f));
            }
            yield break;
        }
        IEnumerator ChangeColor(Color toColor, float duration) {
            Color fromColor = Camera.main.camera.backgroundColor;
            float startTime = Time.time;
            float endTime = Time.time + duration;
            float marginR = toColor.r - fromColor.r;
            float marginG = toColor.g - fromColor.g;
            float marginB = toColor.b - fromColor.b;
            while (Time.time < endTime) {
                fromColor.r = fromColor.r + (Time.deltaTime / duration) * marginR;
                fromColor.g = fromColor.g + (Time.deltaTime / duration) * marginG;
                fromColor.b = fromColor.b + (Time.deltaTime / duration) * marginB;
                Camera.main.camera.backgroundColor = fromColor;
                yield return 0;
            }
            Camera.main.camera.backgroundColor = toColor;
            yield break;
        }
}
*/

public class ofuzake : MonoBehaviour//void OnGUIはResultのコピペ
{
    void OnGUI()
    {
      /*  if (GUI.Button(new Rect(320, 180, 150, 50), "STARTへ戻る"))	//375migi 320 300migi 180                                       if()内で宣言出来るのか！！かんどう
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