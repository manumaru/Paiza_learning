//★クソむずかったｗｗｗｗｗｗｗｗｗ

using System;
public class Hello{
    public static void Main(){

        var nyuryoku = Console.ReadLine();
        //★☆floatだとMath.Cellingによる切り上げできなかった。。浮動小数点数の型の違いか。
        double rad = double.Parse(nyuryoku);
        //rad = Math.Ceiling(rad);
        double r = Math.Pow(rad,2);
        //debag
        //Console.WriteLine(rad);
        // 0<r<=1 で４、 1<r2=2 で16・・つまり４の指数が上がる つまり切り上げた数＝ｎとして４のｎ乗
        //違うわ　４　１６　３６やから２ｘ２，４ｘ４、６ｘ６・・（２ｘrad）＾２‘
        //（半径ｘ２）の2乗のはず・・・いや！ちょうど、斜め途切れるときある？？もしかして。えっ？？ムズ
        //えっ、ムズ。無理やん。
        
        int cnt =0;
        
        for (int i =0; i<=rad; i++)
        {
            for (int j=0; j<=rad; j++)
            {
                double keisan = (Math.Pow(i, 2)+Math.Pow(j, 2));
                if (keisan < r)
                {
                    cnt += 1;
                }
            }
        }
        Console.WriteLine(cnt*4);
        
    }
}