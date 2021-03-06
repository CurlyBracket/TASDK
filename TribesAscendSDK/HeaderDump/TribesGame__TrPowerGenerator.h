#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrPowerGenerator." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrPowerGenerator." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrPowerGenerator." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPowerGenerator : public TrGameObjective
	{
	public:
			ADD_VAR( ::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeScalePlayRate, m_AnimNodeScale )
			ADD_VAR( ::FloatProperty, m_fAutoRestoreHealthEffectsInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAutoRestoreHealthTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nDowntimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bFullyRestoringHealthEffects, 0x2 )
			ADD_VAR( ::BoolProperty, m_bAutoRestoreHealthEnabled, 0x1 )
			ADD_VAR( ::FloatProperty, m_fAutoRestoreHealthTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxMorphDamage, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
