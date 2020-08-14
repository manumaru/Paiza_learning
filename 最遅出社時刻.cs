using System;

public class Mondai{
    public static void Main(){
        //3つのかかる時間を入力
        string minutes = Console.ReadLine();
        string[] zikan =minutes.Split(' ');
        int a = int.Parse(zikan[0]);
        int b = int.Parse(zikan[1]);
        int c = int.Parse(zikan[2]);


        //配座駅に付けばいい時間を想定 分計算 /60と%60で時分に戻せる
        int goal = 60*9 - c -b;
        
        
        //電車の本数分、時刻を要れる。2次元配列。ex：6本なら縦6行。時間と分で横は常に2行。[0]か[1]
        int honsu = int.Parse(Console.ReadLine());
        int[,] table = new int[honsu,2];
        for (int i = 0; i < honsu; i++)
        {
            //数字変換しながらの一括リスト入力、C#じゃ一行では無理なんやろか？
            string station = Console.ReadLine();
            string[] zikokuhyou =station.Split(' ');
            int zi = int.Parse(zikokuhyou[0]);
            int hun = int.Parse(zikokuhyou[1]);
            table[i,0] = zi;
            table[i,1] = hun;
            
            //test
            //Console.WriteLine(table[i,0]);
        }
        

        
        //なるべく遅い時刻からやる。goal over するやつは却下していく
        for (int j = honsu-1; j >-1;  j--)
        {
            int kansan = (table[j,0] )* 60 + (table[j,1]);
            // if goal > kansan =Trueなら、break　＊59分までなので＞＝じゃダメ
            //会社に間に合う最遅の乗車時刻ケース
            if (goal > kansan)
            {
                //分換算で家出る時間
                kansan -= a;
                //戻す
                int ans_zi = kansan / 60;
                int ans_hun = kansan % 60;
                
                string ans = String.Format(
                "{0:D2}:{1:D2}", ans_zi,ans_hun);
                Console.WriteLine(ans);
                //1回（一番遅い便）だけでいいのでBreak
                break;
            }
        }
    }
}