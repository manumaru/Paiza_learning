#pragma strict

function Start () {
}

function Update () {
	
	var animator = GetComponent( Animator );
	
	if( Input.GetKey( KeyCode.Space ) )
	{
		animator.SetBool( "Jump", true );
	}
	
	var state : AnimatorStateInfo = animator.GetCurrentAnimatorStateInfo(0);
	
	if( state.IsName( "Locomotion.Jump" ) )
	{
		animator.SetBool( "Jump", false );
	}
}