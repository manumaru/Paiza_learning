using UnityEngine;
using System;
using System.Collections;
using UnityEngine.UI;
//using Assets.Script;          色とサイズ変更したらここでエラーが起こった

/// <summary>
/// WINとタイトル画面の右上にでるランク表示
/// </summary>

public class Ranksort : MonoBehaviour 
{
	//かなりゴリ押し

                                                                                         /*   public GUIStyle Rank01;
                                                                                            private GUIStyleState RankStyle01;
                                                                                            private GUIStyle Rank02;
                                                                                            private GUIStyleState RankStyle02;
                                                                                            private GUIStyle Rank03;
                                                                                            private GUIStyleState RankStyle03;
                                                                                            private GUIStyle Rank04;
                                                                                            private GUIStyleState RankStyle04;
                                                                                            private GUIStyle Rank05;
                                                                                            private GUIStyleState RankStyle05;
                                                                                            private GUIStyle Rank06;
                                                                                            private GUIStyleState RankStyle06;
                                                                                            private GUIStyle Rank07;
                                                                                            private GUIStyleState RankStyle07;
                                                                                            private GUIStyle Rank08;
                                                                                            private GUIStyleState RankStyle08;
                                                                                            private GUIStyle Rank09;

                                                                                            private GUIStyleState RankStyle09;
                                                                                            private GUIStyle Rank10;
                                                                                            private GUIStyleState RankStyle10;*/
	//private float[] Ranking = new float[9];

	public float [] Ranking = new float[] {10,11,12,13,14,15,16,17,18,19};	//ランキング用の配列         Ranking[] じゃなくてfloat []なんだぜ！
		private float PlayerScore = CountDownbattle.Score;	//クリア時のスコアの呼び出し
        public Text ScoreText01;
        public Text ScoreText02;
        public Text ScoreText03;
        public Text ScoreText04;
        public Text ScoreText05;
        public Text ScoreText06;
        public Text ScoreText07;
        public Text ScoreText08;
        public Text ScoreText09; 
        public Text ScoreText10; 
    //  public GameObject background;
   // public   01 01
    //01          
	// Use this for initialization
	void Start () 
	{
                                                                               /* //フォントサイズ
                                                                                Rank01 = new GUIStyle();
                                                                                Rank01.fontSize = 30;
                                                                                Rank02 = new GUIStyle();
                                                                                Rank02.fontSize = 30;

                                                                                //フォントの色
                                                                                RankStyle01 = new GUIStyleState();
                                                                                RankStyle01.textColor = Color.green;
                                                                                Rank01.normal = RankStyle01;
                                                                                RankStyle02 = new GUIStyleState();
                                                                                RankStyle02.textColor = Color.green;
                                                                                Rank02.normal = RankStyle02;*/

		//ロード処理
		LoadData();

		//ランキングソート
		RankSort();
		Array.Sort(Ranking);	//配列を小さい順に並び替える

		//セーブ処理
		SavaData();
	}
	
	 //Update is called once per frame
	void Update () 
	{
		//Debug.Log(Ranking[5]);	//配列の処理がうまくいっていないのでデバッグログで確認する。
       
                                                                                  /*  background.AddComponent("GUIText");
                                                                                    background.guiText.transform.Translate(0.5f, 0.5f, 0);
                                                                                    background.guiText.anchor = TextAnchor.MiddleCenter;
                                                                                    background.guiText.alignment = TextAlignment.Center;
                                                                                    background.guiText.fontSize = 24;
                                                                                    background.guiText.fontStyle = FontStyle.Normal;
                                                                                    background.guiText.text ="" ;*/
	}
     

	void RankSort()
	{
		//配列を数字の高い順から見ていき、スコアがそれより低い場合は入れ変えりbreak(抜け出す)
		if (PlayerScore > 0)
		{
			for (int i = 9; i >= 0; i--) {//9から降りるようにすること。
				if (Application.loadedLevelName == "WIN") {                                               //おてつきの記録を防止。さらに、WINの時のみ記録。LoadLEvelじゃなくてこうならいけるみたい

					if (PlayerScore < Ranking [i]) {
						Ranking [i] = PlayerScore;                                                               //代入
						break;                                                                      //ここは何をbreak？PlayerScoreか？
					}
				}
			}
		}
	}

	void OnGUI()
	{

		/*
	 	var Rank01 = "1位:" + Ranking[0].ToString() + "秒";           //数字を文字列に変換
		var Rank02 = "2位:" + Ranking[1].ToString() + "秒";           
		var Rank03 = "3位:" + Ranking[2].ToString() + "秒";
		var Rank04 = "4位:" + Ranking[3].ToString() + "秒";
		var Rank05 = "5位:" + Ranking[4].ToString() + "秒";
		var Rank06 = "6位:" + Ranking[5].ToString() + "秒";
		var Rank07 = "7位:" + Ranking[6].ToString() + "秒";
		var Rank08 = "8位:" + Ranking[7].ToString() + "秒";
		var Rank09 = "9位:" + Ranking[8].ToString() + "秒";
		var Rank10 = "10位:" + Ranking[8].ToString() + "秒";
		*/


		// floatの数字をstring型に変換
		var Rank01 = "1st :" + Ranking[0].ToString() ;           //数字を文字列に変換
		var Rank02 = "2nd:" + Ranking[1].ToString() ;           
		var Rank03 = "3rd:" + Ranking[2].ToString() ;
		var Rank04 = "4th:" + Ranking[3].ToString() ;
		var Rank05 = "5th:" + Ranking[4].ToString() ;
		var Rank06 = "6th:" + Ranking[5].ToString() ;
		var Rank07 = "7th:" + Ranking[6].ToString() ;
		var Rank08 = "8th:" + Ranking[7].ToString() ;
		var Rank09 = "9th:" + Ranking[8].ToString() ;
		var Rank10 = "10th:" + Ranking[9].ToString() ;

		// 変換した文字列を表示=>ランキングスコア これだと白くて小さかった
        /*GUI.Label(new Rect(290, 30,100,50), Rank01);              	//変換した文字列を表示//810migi290
    	GUI.Label(new Rect(290, 65,100,50), Rank02);
    	GUI.Label(new Rect(290, 90,100,50), Rank03);
    	GUI.Label(new Rect(290,130,100,50), Rank04);
    	GUI.Label(new Rect(290,150,100,50), Rank05);
    	GUI.Label(new Rect(290,170,100,50), Rank06);
    	GUI.Label(new Rect(290,190,100,50), Rank07);
    	GUI.Label(new Rect(290,210,100,50), Rank08);
    	GUI.Label(new Rect(290,230,100,50), Rank09);
    	GUI.Label(new Rect(290,250,100,50), Rank10);*/

        ScoreText01.text = Rank01;
        ScoreText02.text = Rank02;
        ScoreText03.text = Rank03;
        ScoreText04.text = Rank04;
        ScoreText05.text = Rank05;
        ScoreText06.text = Rank06;
        ScoreText07.text = Rank07;
        ScoreText08.text = Rank08;
        ScoreText09.text = Rank09;
        ScoreText10.text = Rank10;

        //記録のリセット　デバッグ用
    	/*if( GUI.Button(new Rect(60, 400, 130, 50), "Reset SaveData" ))
    	{
    		PlayerPrefs.DeleteAll();
    	}
        */
    }

	//セーブ処理
	void SavaData()	//データのセーブ
	{
		/*
		PlayerPrefs.SetFloat("PlayerData0",Ranking[0]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[1]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[2]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[3]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[4]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[5]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[6]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[7]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[8]);
		PlayerPrefs.SetFloat("PlayerData0",Ranking[9]);


		/*
		for( int i = 0; i<10; i++)
		{
			PlayerPrefs.SetFloat("PlayerData[i]", Ranking[i]);
		}
		*/



		PlayerPrefs.SetFloat("PlayerData0", Ranking[0]);                                    //PlayerPrefs.Set変数で値の取り出し
		PlayerPrefs.SetFloat("PlayerData1", Ranking[1]);
		PlayerPrefs.SetFloat("PlayerData2", Ranking[2]);
		PlayerPrefs.SetFloat("PlayerData3", Ranking[3]);
		PlayerPrefs.SetFloat("PlayerData4", Ranking[4]);
		PlayerPrefs.SetFloat("PlayerData5", Ranking[5]);
		PlayerPrefs.SetFloat("PlayerData6", Ranking[6]);
		PlayerPrefs.SetFloat("PlayerData7", Ranking[7]);
		PlayerPrefs.SetFloat("PlayerData8", Ranking[8]);
		PlayerPrefs.SetFloat("PlayerData9", Ranking[9]);

	}

	
	//ロード処理
    /*
	void LoadData()                                                                
	{
		for(int i = 0; i < 5; i++)
		{
			Ranking[i] = PlayerPrefs.GetFloat("PlayerData[i]");
		}

	}*/
	
	void LoadData()	//保存されたデータの読み込み
	{
		
		if ( PlayerPrefs.HasKey("PlayerData0") )                                                //PlayerPrefs.HasKeyで値が入っているか確認
		{
			Ranking[0] = PlayerPrefs.GetFloat("PlayerData0");                       //PlayerPrefs.Get変数で値の取り出し
			Ranking[1] = PlayerPrefs.GetFloat("PlayerData1");
			Ranking[2] = PlayerPrefs.GetFloat("PlayerData2");
			Ranking[3] = PlayerPrefs.GetFloat("PlayerData3");
			Ranking[4] = PlayerPrefs.GetFloat("PlayerData4");
			Ranking[5] = PlayerPrefs.GetFloat("PlayerData5");
			Ranking[6] = PlayerPrefs.GetFloat("PlayerData6");
			Ranking[7] = PlayerPrefs.GetFloat("PlayerData7");
			Ranking[8] = PlayerPrefs.GetFloat("PlayerData8");
			Ranking[9] = PlayerPrefs.GetFloat("PlayerData9");
		}

		/*
		PlayerPrefs.GetFloat("PlayerData0");
		PlayerPrefs.GetFloat("PlayerData1");
		PlayerPrefs.GetFloat("PlayerData2");
		PlayerPrefs.GetFloat("PlayerData3");
		PlayerPrefs.GetFloat("PlayerData4");
		PlayerPrefs.GetFloat("PlayerData5");
		PlayerPrefs.GetFloat("PlayerData6");
		PlayerPrefs.GetFloat("PlayerData7");
		PlayerPrefs.GetFloat("PlayerData8");
		PlayerPrefs.GetFloat("PlayerData9");
		*/
		

	}



}