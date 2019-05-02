#pragma strict

function OnTriggerEnter( col : Collider )
{
	if( col.tag == "Player" )
	{
		Application.LoadLevel( Application.loadedLevel );
	}
}