"""
高階関数、調べたけどまだ使わんかった。他 引数でinput入力と戻り値でreturn,ふたつの関数に小分けなど挑戦。

⇒同じ変数を使う場合は、2つの関数の外で定義。⇒カプセル化できないのでやめた。returnも、値一行で返すのが基本
なのでこの問題の形式はprint()が向いてる。
"""

def judge(x):
    x= int(x)

    zu=[]
    goukei=0
    #0の位置。index１まで入る
    empty_h=[]
    empty_l=[]

    for h in range(x):
        #2次元配列作成
        zu.append(list(map(int, input().split())))
        #print(zu[h])
        
        #続いて魔法陣の各辺の値だが、「２マス」までしか空白にならないのでmax更新し続けて保持したら無事に出せる。
        if goukei < sum(zu[h]):
            goukei = sum(zu[h])
    
        if 0 in zu[h]:
            for l in range(x):
                if zu[h][l] == 0:
                    empty_h.append(h)
                    empty_l.append(l)
                    #ぃよし。これで0の位置取得できた。思ったより数行のコードでできたな。・・
    

    #同じ行に0がある場合、縦に見て出す. この場合のみ、縦でリスト化する。
    if empty_h[0] == empty_h[1]:
        tate1 = []
        tate2 = []
        for a in range(x):
            tate1.append(zu[a][empty_l[0]])
            tate2.append(zu[a][empty_l[1]])
    
        zu[empty_h[0]][empty_l[0]] = goukei - sum(tate1)
        zu[empty_h[1]][empty_l[1]] = goukei - sum(tate2)
    
    
    #同じ縦列に存在しる場合　いやココと3つ目、同じ処理で行けるわ。横穴１つだから。
    #elif empty_l[0] == empty_l[1]:
        
    #完全にバラバラな位置の場合。  足りてない数値を0に上書き
    else:
        zu[empty_h[0]][empty_l[0]] = goukei - sum(zu[empty_h[0]])
        zu[empty_h[1]][empty_l[1]] = goukei - sum(zu[empty_h[1]])
        
    
    for j in range(x):
        str_list = map(str,zu[j])
        ans =" ".join(str_list)
        print(ans)


judge(input())
