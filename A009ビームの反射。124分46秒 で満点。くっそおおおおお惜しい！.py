A009:ビームの反射
----------------------------------------------------------------------------------------
内部が格子状の正方形の区画に分けられ、一部の区画に鏡が配置された箱を考えます。
今、その箱を上部から眺めているものとし、箱の高さは考えないことにします。
鏡は区画の対角線上に配置され、1つの区画には1枚の鏡を配置することができます。

鏡のない区画を'_' 、端点が区画の右上および左下の頂点であるような対角線の上に配置された鏡を'/'、もう一方の対角線上に配置された鏡を'\' で表すこととする。

高さが3, 幅が5 の箱の例として次があげられます。
(環境によりバックスラッシュが円マークで表示される可能性があります)
__\_/
___/_
\/\_/
----------------------------------------------------------------------------------------
入力例1
3 5
__\_/
___/_
\/\_/
出力例1
9
入力例2
4 4
___\
_\__
____
_\_/
出力例2
12
入力例3
3 2
_\
//
\/
出力例3
7
----------------------------------------------------------------------------------------
#x,y = map(int,input().split())
#いつもと違うやり方
x,y=(int(j) for j in input().split())

#ビームの動き方は12種類　4種の直線ベクトルと4種のぶつかりかたｘ2向き
#1マスごとの、効果として考える

listo = []
kara=[]
count=0
i=0#縦
j=0#横
beam_yoko = True
hidarimuki = False
uemuki = False

#2次元配列化
for m in range(x):
    mojis = input()
    #Unicode コードポイントが整数 i である文字を表す文字列を返すchr(i)
    ichiji = mojis.replace("\\",chr(165))
    ichiji = list(ichiji)
    listo.append(ichiji)
   # print(listo[m])


while True:
    #ビームが横の時
    if beam_yoko == True:
        #2通り
        if listo[i][j] == "_":
            if hidarimuki == False:
                j += 1
                count +=1
                if j > y-1 :
                    break
            else:
                j -= 1
                count +=1
                if j < 0:
                    break
        #2通り
        elif listo[i][j] == "/":
            if hidarimuki == False: 
                i -= 1
                uemuki = True
                count +=1
                if i < 0:
                    break
            else:
                i +=1
                uemuki = False
                count +=1
                if i > x-1:
                    break
            beam_yoko = False
        #2通り
        else:#\
            if hidarimuki == False:
                i += 1
                uemuki = False
                count +=1
                if i > x-1 :
                    break
            else:
                i -= 1
                uemuki = True
                count +=1
                if i < 0:
                    break
            beam_yoko = False
    #ビームが縦の時
    else:
        #2通り
        if listo[i][j] == "_":
            if uemuki == False:
                i += 1
                count +=1
                if i > x-1 :
                    break
            else:
                i -= 1
                count +=1
                if i < 0 :
                    break
        #2通り
        elif listo[i][j] == "/":
            if uemuki == False:
                j -= 1
                hidarimuki = True
                count +=1
                if j < 0 :
                    break
            else:
                j += 1
                hidarimuki = False
                count +=1
                if j > y-1 :
                    break
            beam_yoko = True
        #2通り
        else:#\
            if uemuki == False:
                j +=1
                count+=1
                hidarimuki = False
                if j > y-1 :
                    break
            else:                
                j -= 1
                count +=1
                hidarimuki = True
                if j <0  :
                    break
            beam_yoko = True
   #print(i,j,uemuki,hidarimuki)

        
    
print(count)    

"""
\  /  \
\  /  /

ビームが横の時と縦の時で分けたほうがいいか？
"""
