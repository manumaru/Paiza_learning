h,w,n = map(int,input().split())

trmp=[]

for i in range(h):
    trmp.append(list(map(int,input().split())))    
#print(trmp)
rec = int(input())

junban = 0
ply=[]
#慣れるため敢えて内包表記
[ply.append(0) for i in range(n)]

for i in range(rec):
    a,b,x,y= map(int,input().split())
 
    #n人目がｍｓったとき、junban=1を代入しなおせばよい
    while junban <= n:
        if trmp[a-1][b-1] == trmp[x-1][y-1]:
            ply[junban] +=1
            break   

        else:
            junban += 1
            if junban == n:
                junban = 0
            break
    #print(ply)

#リストの各要素を2条して新しいリストに格納する内包表記
ans = [i*2 for i in ply]
#print(ply)
[print(ans[i]) for i in range(len(ans)) ]

