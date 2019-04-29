x = int(input())


for i in range(x):
    answer=""
    word = input()
    word = list(word)
    #最後の文字で検索をかける
    if word[-1] in "sox":
        #appendでなく複数同時追加
        word.extend(["e","s"])
    elif word[-1] =="h":
        if word[-2] in "sc":
             word.extend(["e","s"])
        else:
            word.append("s")
    elif word[-1] == "f":
        del word[-1]
        word.extend(["v","e","s"])
    elif word[-1] =="e" and word[-2] == "f":
        del word[-2:]
        word.extend(["v","e","s"])
    elif word[-1] =="y":
        #この書き方、構文エラ`ーだった
        #if word[-2] not= "a" or"i" or "u" or "e" or "o":
        if word[-2] not in "aiueo":
            del word[-1]
            word.extend(["i","e","s"])
        else:
            word.append("s")
    else:
        word.append("s")
    
    for j in word:
        answer += j
    print(answer)
    