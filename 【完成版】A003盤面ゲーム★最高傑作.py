"""----------------------------------------------------------------
B=1,W=0とする。　←"B"や"W"として扱わない！

●クラス・ユーザー定義関数、returnと内包表記。8方向を「~1～1」でベクトル付けしておこうなう発想、
同クラス内の別メソッド内からの、self.による他メソッド呼び出し、タプルに.formatを使ったprint、0付け。
map関数なしでのシンプルなsplit()でのinput()標準入力。

☆☆色々、めっちゃ勉強になった！！！
    ----------------------------------------------------------------"""
kaisu = int(input())

class Boardgame():

    #初期化メソッド
    def __init__(self):
        self.osero = []

        #盤面作成。8x8マスの2次元配列。
        for h in range(8):
            #★内包表記の練習。 8回None
            self.osero.append([None for i in range(8)])
        #初期配置
        self.osero[3][3] = 0
        self.osero[4][4] = 0
        self.osero[3][4] = 1
        self.osero[4][3] = 1



    #石を置くメソッド  ★TrueとFalseをreturnで返す！　⇒★☆返さなくてもいいが、返しても問題なかった。ｂ
    def put(self,x,y,player):
        
        #既に石がある場合
        if self.osero[y][x] is not None:
            return False
        

        #何も裏返せない場合
        #★★re_verse関数内のローカル変数「area」はここで取得できないので、再定義。。てかreturnで取得。
        #★self.～～で、同じクラス内の別メソッドも取得。すごい！ ★引数もこの中で、『同じヤツ』渡せるのか！！
        area = self.re_verse(x,y,player)
        if area == []:
            return False


        #できる場合  ★引数playerにより、白（０）か黒（１）か一つのコードで変えれる！すごい
        self.osero[y][x] = player
        #タプルから1組ずつ取り出す。
        for x,y in area:

            #入れ替えれる石のリストarea内の座標、すべてplayerの石の色に変更。
            self.osero[y][x] = player
        
        return True



    #裏返すメソッドの定義  ★8方向調べる。 ★★put関数内で呼び出してるので。これ単体で呼び出す必要がない！
    def re_verse(self,x,y,player):
        #距離と向きを表現
        vector = [-1,0,1]
        area = []
    
        for x_vector in vector:
            for y_vector in vector:
                #★★8方向・・できる9回の内、「どこへも向かわない」1方向のベクトルの時は、Skipして続ける。
                if x_vector == 0 and y_vector == 0:
                    continue
                
                #裏返せる可能性の★一時リスト。⇒裏★返すかどうかは、最後までにPlayerの石があったかなど条件が成立次第。
                possibility = []
                #向きを操る変数
                depth = 0
                
                #裏返せない場合の、break処理できるまで続ける。
                while(True):
                    depth += 1
                    
                    #vector計算。
                    x_i = x + (x_vector * depth)
                    y_i = y + (y_vector * depth)
                
                    #8x8マスに収まりきる間続ける
                    if 0 <= x_i < 8 and 0 <= y_i < 8:
                        req =self.osero[y_i][x_i]
                        
                        #★未獲得マス（None）は裏返せない。 `それ以降続かないのでbreak!!
                        #if is使用！！！
                        if req is None:
                            break
                        
                        #自分の石が見つかった時。★この時初めて、裏返せるareaに追加。
                        if req ==  player:
                            #更にそれまでに相手の石があった場合↓
                            # ★「！」をつかった、「空じゃない場合」の表現！！
                            if possibility != []:
                                area.extend(possibility)
                                break
                            # なかった場合(breakしなくても動くが、★処理時間短縮のため)
                            else:
                                break
        
                        #相手の石が見つかった時。
                        else:
                            #可能性（possibility）リストに一旦★「タプル」形式で保存。
                            possibility.append((x_i,y_i))
    
                    #8x8マス範囲を超えた場合。
                    else:
                        break
                
        #★戻り値に「ひっくりかえす石座標をタプルで格納したリスト」areaを指定。
        return area
    


#★インスタンスの生成。
board = Boardgame()


for x in range(kaisu):
    #map関数使わなきゃ、数字のまま入れれる！（今回は元々strなのでそこまで意味ない）
    hand = input().split()

    te_x = int(hand[1]) -1#　盤のindexに合わせて、１ずつここで減らしておく。
    te_y = int(hand[2]) -1
    
    if hand[0] == "B":
        #黒を示す色は１
        board.put(te_x,te_y,1)
        
        """-----------------------------------------------
        #「挟まれている」Wがあるか確認。　タテヨコナナメすべて。
        #★ココの処理がこの問題の肝だったが↑のクラス内でつくった。
        -----------------------------------------------"""
        
    elif hand[0] == "W":
        #白を示す色は０
        board.put(te_x,te_y,0)

    #オマケ。なくていい
    else:
        print("Error")
        break
        
#それぞれ個数をカウント。★★遂に内包表記、自作できるようになってきた！
white =[ r.count(0) for r in board.osero]
black =[ r.count(1) for r in board.osero]
w = sum(white)
b = sum(black)

#勝敗記述  ★「埋める文字を0として右寄せ」した、★★「.format」によるゼロ埋め
if b > w:
    answer = '{:0=2}-{:0=2} The black won!'.format(b,w)
elif w > b:
    answer = '{:0=2}-{:0=2} The white won!'.format(b,w)
    
#引き分け
else:
    answer = '{:0=2}-{:0=2} Draw!'.format(b,w)

print(answer)
