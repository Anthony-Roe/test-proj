class ACL_BusinessManager : EPF_PersistentScriptedState
{
    int m_iValue;
	
	void Inc()
	{
		m_iValue++;
	}
}
[
    EPF_PersistentScriptedStateSettings(ACL_BusinessManager),
    EDF_DbName.Automatic()
]
class ACL_BusinessManagerSaveData : EPF_ScriptedStateSaveData
{
    int m_iValue;
}

modded class EPF_BasicRespawnSystemComponent
{
	
	override void OnPlayerRegistered_S(int playerId)
	{
		super.OnPlayerRegistered_S(playerId);
		
		Print("registered");
		
		ref ACL_BusinessManager manager();
		
		for (int i = 0; i < 5; i++)
		{
			manager.Inc();
		}
		
		Print(manager.m_iValue);
		manager.Save();
	}
	
	//------------------------------------------------------------------------------------------------
	override protected void GetCreationPosition(int playerId, string characterPersistenceId, out vector position, out vector yawPitchRoll)
	{
		super.GetCreationPosition(playerId, characterPersistenceId, position, yawPitchRoll);
		Print("spawning");
	}
}