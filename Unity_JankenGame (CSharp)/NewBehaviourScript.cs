using UnityEngine;
using System.Collections;

/// レンダラーやαなどからフェードアウトっぽく思うが詳しくわからないのでこのまま放置　下手にいじりません  →フェードインらしい
/// んで下2行をコメント文にしたら、FadeOutScript.csと完全に一致する。片方のみでイイらしい。

/// 

public class NewBehaviourScript : MonoBehaviour
{
	Color alpha = new Color(0, 0, 0, 0.01f);
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
	    if(renderer.material.color.a >= 0)
		    renderer.material.color -= alpha;
        if (renderer.material.color.a <= 0)         //●この一行追加で少し待ってからちゃんと切り替わるようになったが、 <=0を仕組み理解せずやったのでぎこちないという問題点
        Application.LoadLevel("Main");                //ここのみを入れたらすぐMainがロードされていた。
	}
}
