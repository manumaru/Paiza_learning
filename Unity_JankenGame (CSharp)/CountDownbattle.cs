using UnityEngine;
using System.Collections;
//-----------------------------------------
/*
        *概要
        このスクリプトだけで
		
        コンピュータの手の決定
        プレイヤーの手の決定
        また数値に対応した向きへオブジェクトを回転させる。
        勝敗判定からシーンの移動。
        カウントアップ処理と表示。

        ができると思います。

   一旦エラーがイキナリ50増えた原因：スクリプトコピーしていじってたから、同名のものが複数存在したため→片方コメントで囲うとおｋになった。   
 * 
*/

//-----------------------------------------
public class CountDownbattle : MonoBehaviour
{
    public float StartTime ;//スタート時刻の設定、変数   =0.0fから指定なしに変更     ←これが原因のひとつ。StartTimeが2つの用途で使われてる。CPU手のタイミングで減る(--)のに対し、反射速度で増える(++)ので常に0だった
    public float CountTime =0.0f ;                                                                   //ここがおかしかった。CPUの手が出る命令で開始に変更せよ。
    public int Player,Computer;
    public GameObject CPU, Person;
    public static float Score = 0.0f;                                                                   //●CountTime代入の命令で「=0.0f」はいる？これがあるから動くのかも

    // Use this for initialization
    void Start()
    {
        StartTime = Random.Range(1.8f, 3.4f);               
        Debug.Log(StartTime);  //サイトでここDebug.log入れてた　StartTimeを入れて正しいかどうかなんてもう知らない！メイのパカ！

    }

    // Update is called once per frame



    void Update()
    {
        //CountUp();		//カウントアップ処理
        PlayerHand();	//プレイヤーの手を選択させる
        Judge();		//判定
        //一番下にカウントアップのONGUI関数

        countdown();

        if (StartTime <= 0 && StartTime >= -0.02f)          //イコール(==)はさすがのパソコンでもfloat単位となると必ず取得できるわけではない。以下に戻したらとまらないので1回の更新周期くらいに指定 というせこい手
        {
            CPU = GameObject.Find("CPU");//CPUの手のオブジェクトデータ取得    Unityで選んだのでなくてもいいだろうが一応
            int cphand;                                                                    //ここで定義できるのか。あとUpdateでもif条件が1回なので1回だけ行える！かがく　の　ちからって　スゲー！！
            cphand = Random.Range(0, 3);
            if (cphand == 0)        //paa
            {
                CPU.transform.rotation = Quaternion.Euler(0, 90, 0);
                Computer = 0;
                Debug.Log("パー");
            }
            else if (cphand == 1)      //guu
            {
                CPU.transform.rotation = Quaternion.Euler(0, 270, 0);
                Computer = 1;
                Debug.Log("グー");
            }
            else if (cphand == 2)       //choki
            {
                CPU.transform.rotation = Quaternion.Euler(0, 180, 0);
                Computer = 2;
                Debug.Log("チョキ");
            }
        }
        if (StartTime <=0)                                                              //3行追加、反射時間の計測増加
        {
            CountTime += Time.deltaTime;//毎フレームごとに秒数加算させるための準備
        }
    }


    void countdown()
    {
        StartTime -= Time.deltaTime;//毎フレームごとに秒数加算させるための準備                          よくみて！「-」があるからね！マイナスを加算といってるのだ！
       //Debug.Log(StartTime);                                                                  ●ここで1回の更新周期を0.02fくらいと考えました
    }




    /// <summary>
    /// プレイヤーからの入力を受け取り、グーチョキパーの数値を格納する処理。
    /// </summary>
    void PlayerHand()                                                            
    {
        if (Computer == 0 || Computer == 1 || Computer == 2 )                                   //おてつきは禁止した　連打する奴が最速とかんんｗｗありえないｗｗｗ    
        {
            Person = GameObject.Find("Person");//プレイヤーの手を表すオブジェクトのデータ取得　　　　Unityで選んだのでなくてもいいだろうが一応

            //0:パー 1:グー 2:チョキ
            if (Input.GetKeyDown(KeyCode.LeftArrow))//グー(←キーを押してYを軸にcpjankenを時計回りに90度回転)
            {
                Person.transform.rotation = Quaternion.Euler(0, 270, 0);
               // StartCoroutine("delay");//
                Player = 1;
                Score = CountTime;

            }

            else if (Input.GetKeyDown(KeyCode.DownArrow))//チョキ(↓キーを押してYを軸にcpjankenを時計回りに90度回転)
            {
                Person.transform.rotation = Quaternion.Euler(0, 180, 0);
               // StartCoroutine("delay");//
                Player = 2;
                Score = CountTime;
            }

            else if (Input.GetKeyDown(KeyCode.RightArrow))//パー(→キーを押してYを軸にcpjankenを時計回りに270度回転)
            {
                Person.transform.rotation = Quaternion.Euler(0, 90, 0);
                
               // StartCoroutine("delay");//
                Player = 0;
                Score = CountTime;
            }

            //Debug.Log(Player);                                           こちらも流れてしまう原因なので一時停止
           // System.Threading.Thread.Sleep(3000); 失敗
        }
        else if (Computer == -1 && Input.GetKeyDown(KeyCode.LeftArrow) || Input.GetKeyDown(KeyCode.DownArrow) || Input.GetKeyDown(KeyCode.RightArrow))
        {
            Application.LoadLevel("Otetsuki");//
        }
    }
    /// <summary>
    /// delayを追加したができない
    /// </summary>
    /// <returns></returns>
   /* IEnumerator delay()
    {
        yield return new WaitForSeconds(3.2f);
    }*/




    /// <summary>
    /// ComputerとPlayerを比較して勝敗判定を下す。
    /// </summary>
	void Judge()
    {
        //0:パー 1:グー 2:チョキ

        if (Player == 1 && Computer == 2)
        {
           
            Application.LoadLevel("WIN");
           // StartCoroutine("NextStageWIN");                                               //なにそれそんな行き方できんの！？
        }

        //下のelse２つに問題あり                     ←やってみました　           解決
        else if (Player == 2 && Computer == 0)
        {
            Application.LoadLevel("WIN");
           // StartCoroutine("NextStageWIN"); 

        }
        else if (Player == 0 && Computer == 1)
        {
            Application.LoadLevel("WIN");
           // StartCoroutine("NextStageWIN"); 

        }
        //チョキでグーに負け
        else if (Player == 2 && Computer == 1)
        {
           // StartCoroutine("NextStageLOSE"); 
            Application.LoadLevel("LOSE");
        }
        //パーでチョキに負け
        else if (Player == 0 && Computer == 2)
        {
           // StartCoroutine("NextStageLOSE"); 
            Application.LoadLevel("LOSE");
        }
        //グーでパーに負け
        else if (Player == 1 && Computer == 0)
        {
            // StartCoroutine("NextStageLOSE"); 
            Application.LoadLevel("LOSE");
        }
        //グーであいこ負け
        else if (Player == 0 && Computer == 0)
        {
           // StartCoroutine("NextStageLOSE"); 
            Application.LoadLevel("LOSE");
        }
        //チョキであいこ負け
        else if (Player == 1 && Computer == 1)
        {
           // StartCoroutine("NextStageLOSE"); 
            Application.LoadLevel("LOSE");
        }
        //パーであいこ負け
        else if (Player == 2 && Computer == 2)
        {
           // StartCoroutine("NextStageLOSE"); 
            Application.LoadLevel("LOSE");
        }

    }




    /*
     * //中身のCountTimeの一行だけUpdateにコピってCountUpの宣言をコメント文にして消しますね　→うまくいったかもしんない
     * <summary>
    /// カウントアップ処理。Updataに入れることによって毎フレームごと秒数加算
    /// </summary>
    void CountUp()
    {
        CountTime += Time.deltaTime;//毎フレームごとに秒数加算させるための準備
    }*/



    /// <summary>
    /// カウントアップ秒数表示
    /// </summary>
    /*                                  ここをプログラムに戻すとメイン画面に反射時間がリアルタイムで数えているのが見える
    void OnGUI()
    {
        //カウントアップを表示させる処理
        var Timer = CountTime.ToString();			//数字を文字列に変換
        GUI.Label(new Rect(20, 20, 100, 50), Timer);//変換した文字列を表示     
    }
    */


    /*IEnumerator NextStageWIN()
    {   
        yield return new WaitForSeconds(0.4f);
        Application.LoadLevel("WIN");
    }

    IEnumerator NextStageLOSE()
    {
        yield return new WaitForSeconds(0.4f);
        Application.LoadLevel("LOSE");
    }*/
}