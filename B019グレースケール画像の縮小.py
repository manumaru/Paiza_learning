x,y = map(int, input().split())

listo = []

#2次元配列に格納
for i in range(x):
    listo.append(list(map(int,input().split())))

z = int(x/y)
answers = []

#x行目のブロック区切り
for g in range(z):
    g_a = y*g
    #y列目のブロック区切り
    for h in range(z):
        h_a = y*h

        #各ブロックの平均算出
        heikin=0
        for i in range(y):
            for j in range(y):
                #print(i,j,g_a,h_a)
                heikin += listo[i+g_a][j+h_a] 
        answers.append(int(heikin/y**2))

#print(answers)

#yｘyマスのブロックの形にリストを分割する関数を定義
def spl(m,n):
    ## ↓ ★0～2,3～5,6～8のような指定が出来る書き方。すげぇ
    
    #start,stop,stepの３つ引数指定。
    for i in range(0,len(m),n):
        #スライスしてyieldで戻り値として返す
        yield m[i:i+z]

answer = list(spl(answers,z))

for i in range(z):
    ans = answer[i]
    #文字列に変換
    ans_str = [str(n) for n in ans]
    #y個ずつ格納されたリスト内の数字（str）を、それぞれ空白で結合(joint)して一行にまとめて出力。
    a = ' '.join(ans_str)
    print(a)
    