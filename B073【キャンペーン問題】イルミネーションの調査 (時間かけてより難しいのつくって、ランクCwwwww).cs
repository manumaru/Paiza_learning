using System;

public class Hello{
    public static void Main(){
        // 自分の得意な言語で
        // Let's チャレンジ！！

        string first = Console.ReadLine();
        string[] total =first.Split(' ');
        int tree_count = int.Parse(total[0]);
        int avg_norma = int.Parse(total[1]);

        string second = Console.ReadLine();
        string[] datas =second.Split(' ');
        //★初期値入れないとコンパイルエラーなる
        int[] kosu = new int[tree_count];
        for (int i = 0; i < tree_count; i++)
        {
            //ｎ本目のでんきゅうすうでーたのついか
            //★Array関数で配列の要素数1個追加　→いらなかった
            //Array.Resize(ref kosu, kosu.Length + 1);
            int henkan = int.Parse(datas[i]); 
            //最後尾に代入
            //kosu[kosu.Length - 1] = henkan;
            kosu[i] = henkan;
            //test 個数はあってる。ここの電球は
            //Console.Write(kosu[i]);
        }
        string kaisustr = Console.ReadLine();
        int kaisu = int.Parse(kaisustr);
        
        for (int j = 0; j < kaisu; j++)
        {
            //入力される二つの値a,bのインデックス番目の間で平均算出してavg_normaと比較
            string third = Console.ReadLine();
            string[] startend =third.Split(' ');
            int st = int.Parse(startend[0]);
            int end = int.Parse(startend[1]);
            //初期化
            int keisan = 0;
            //平均出す前の合算
            for (int g = -1; g < end -st ; g++)
            {
                keisan += kosu[st+g];
            }
            //test
            //Console.WriteLine(keisan);
            
            //足りなかったときの電極追加処理（一番左から順に、「均等に」やるらしい）
            //5,6,7 5,6,7って増やす処理要るな。電極1個ずつ足すのに
            int cnt = 0;
            int tasu =0;
            while (keisan/(end-st+1) < avg_norma)
            {
                for (int h = -1; h <end-st; h++)
                {
                    kosu[st+h] +=1;
                    tasu += 1;
                }
                if ((keisan+tasu)/(end-st+1) >= avg_norma  )
                {
                    break;
                }
                /*
                kosu[st-1+cnt] +=1 ;
                tasu +=1;
                
                //平均以上になったら抜ける  ←★★★★難しくかいてたｗｗｗｗｗ　全部1個足せばいいらしい
                if ((keisan+tasu)/(end-st+1) >= avg_norma  )
                {
                    Console.WriteLine(keisan);
                    Console.WriteLine(tasu);
                    Console.WriteLine(end-st+1);
                    Console.WriteLine(avg_norma);
                    Console.Write("結果；");
                    foreach (var tes in kosu)
                    {
                        Console.Write(tes);
                    }
                    break;
                }
            
                //始点から終点繰り返す処理
               cnt +=1;
               if (cnt == end-st+1)
               {
                    cnt = 0;   
               }
               //Console.WriteLine(keisan+tasu);
               */
            }
        }
        
        var ans ="";
        foreach (var a in kosu)
        {
            string an = a.ToString();
            //別の書き方
            //string an = Convert.ToString(a);
            ans += an+" ";
        }
        //最後の空白削除
        Console.Write(ans.Trim());
    }
}