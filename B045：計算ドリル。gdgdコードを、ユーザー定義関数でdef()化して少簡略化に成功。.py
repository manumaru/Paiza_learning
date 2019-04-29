import random
#paiza問題で初import。
#random.randint(開始数,終了数) 整数生成。

#●ユーザー定義関数を使うと、変数名でたくさんおこられた。残り2分なので、次回リベンジする。

x,y= map(int,input().split())

mondai_list =[]

#ユーザー関数定義での行数削減に成功
def keisan():
    global hidari
    global migi
    hidari = (random.randint(0,99))
    migi = (random.randint(0,99))

def tashizan():
    global hidari
    global migi
    hidari = str(hidari)
    migi= str(migi)
    mondai_list.append(hidari+" + "+migi+" =")

def hikizan():
    global hidari
    global migi
    hidari = str(hidari)
    migi= str(migi)
    mondai_list.append(hidari+" - "+migi+" =")
    
#足し算問題を追加
for i in range(x):
    keisan()
    while hidari + migi >99:
        keisan()
    tashizan()

a = len(mondai_list)
b = len(set(mondai_list))

#★重複がある限り足し算問題を再生成 ifでも可 setで重複をはじく
while a != b:
    c= a-b
    #重複の削除
    mondai_list = list(set(mondai_list))
    #回数分再生成
    for j in range(c):
        keisan()
        while hidari + migi >99:
            keisan()
        tashizan()
        
    a = len(mondai_list)
    b = len(set(mondai_list))


#引き算問題を追加
for i in range(y):
    keisan()
    #答えがマイナスにならないように調整
    while hidari - migi <0:
        keisan()
    hikizan()

a = len(mondai_list)
b = len(set(mondai_list))

#★重複がある限り足し算問題を再生成 ifでも可 setで重複をはじく
while a != b:
    c=a-b
    #重複の削除
    mondai_list = list(set(mondai_list))
    #回数分再生成
    for j in range(c):
        keisan()
        while hidari - migi <0:
            keisan()
        hikizan()
    a = len(mondai_list)
    b = len(set(mondai_list))

#シャッフル
random.shuffle(mondai_list)

for i in range(x+y):
    print(mondai_list[i])
