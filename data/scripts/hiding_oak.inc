HidingOak_EventScript_ResetHunt::
    setvar VAR_HIDDEN_OAK_FOUND_COUNTER, 0
    setvar VAR_HIDDEN_OAK_FLAG_OFFSET, 0
    call HidingOak_EventScript_RecursivelyHideAllOaks
    setvar VAR_HIDDEN_OAK_HUNT_STATUS, 1
	end

HidingOak_EventScript_StartHunt::
	msgbox HidingOak_Text_SpawnOaks, MSGBOX_SIGN
    setflag FLAG_HIDE_OAK_IN_HIS_LAB
    givemon SPECIES_EEVEE, 25
    setvar VAR_HIDDEN_OAK_SPAWN_COUNTER_INDEX, 0
    call HidingOak_EventScript_RecursivelySpawnOaks
	warp MAP_PALLET_TOWN, 8, 16
    setvar VAR_HIDDEN_OAK_HUNT_STATUS, 2
	end

HidingOak_EventScript_TryEndHunt::
    goto_if_eq VAR_HIDDEN_OAK_HUNT_STATUS, 1, HidingOak_EventScript_HuntNotStarted
    goto_if_eq VAR_HIDDEN_OAK_HUNT_STATUS, 2, HidingOak_EventScript_HuntFailure
    goto_if_eq VAR_HIDDEN_OAK_HUNT_STATUS, 3, HidingOak_EventScript_HuntSuccess
	end

HidingOak_EventScript_RecursivelyHideAllOaks::
    setflagwithoffset HIDDEN_OAK_INVISIBLE_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET
    addvar VAR_HIDDEN_OAK_FLAG_OFFSET, 1
    goto_if_le VAR_HIDDEN_OAK_FLAG_OFFSET, (MAX_HIDDEN_OAK_COUNT - 1), HidingOak_EventScript_RecursivelyHideAllOaks
    return

HidingOak_EventScript_RecursivelySpawnOaks::
    random MAX_HIDDEN_OAK_COUNT
    copyvar VAR_HIDDEN_OAK_FLAG_OFFSET, VAR_RESULT
    goto_if_unsetwithoffset HIDDEN_OAK_INVISIBLE_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET, HidingOak_EventScript_RecursivelySpawnOaks
    clearflagwithoffset HIDDEN_OAK_INVISIBLE_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET
    addvar VAR_HIDDEN_OAK_SPAWN_COUNTER_INDEX, 1
    goto_if_lt VAR_HIDDEN_OAK_SPAWN_COUNTER_INDEX, HIDDEN_OAK_SPAWN_COUNT, HidingOak_EventScript_RecursivelySpawnOaks
    return

HidingOak_EventScript_HuntNotStarted::
    msgbox HidingOak_Text_HuntNotStarted, MSGBOX_SIGN
    end

HidingOak_EventScript_HuntSuccess::
    playfanfare MUS_OBTAIN_BADGE
    buffernumberstring STR_VAR_1, VAR_HIDDEN_OAK_TIMESTAMP_HOURS
    buffernumberstring STR_VAR_2, VAR_HIDDEN_OAK_TIMESTAMP_MINUTES
    buffernumberstring STR_VAR_3, VAR_HIDDEN_OAK_TIMESTAMP_SECONDS
    msgbox HidingOak_Text_HuntSuccess, MSGBOX_SIGN
    return

HidingOak_EventScript_HuntFailure::
    buffernumberstring STR_VAR_1, VAR_HIDDEN_OAK_FOUND_COUNTER
    buffernumberstring STR_VAR_2, HIDDEN_OAK_SPAWN_COUNT
    msgbox HidingOak_Text_HuntFailure, MSGBOX_SIGN
    return

HidingOak_EventScript_DefeatedOak::
    addvar VAR_HIDDEN_OAK_FOUND_COUNTER, 1
    call_if_eq VAR_HIDDEN_OAK_FOUND_COUNTER, HIDDEN_OAK_SPAWN_COUNT, HidingOak_EventScript_SetHuntCompleted
    return

HidingOak_EventScript_SetHuntCompleted::
    storetimestamp VAR_HIDDEN_OAK_TIMESTAMP_HOURS, VAR_HIDDEN_OAK_TIMESTAMP_MINUTES, VAR_HIDDEN_OAK_TIMESTAMP_SECONDS
    setvar VAR_HIDDEN_OAK_HUNT_STATUS, 3
    return

HidingOak_EventScript_FoundOak_1::
	trainerbattle_single TRAINER_HIDDEN_OAK_1, HidingOak_Text_NewlyFoundOak, HidingOak_Text_DefeatedOak, HidingOak_EventScript_DefeatedOak, NO_MUSIC
    msgbox HidingOak_Text_PreviouslyFoundOak, MSGBOX_NPC
	msgbox HidingOak_Text_SecretPhrase_1, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_2::
    trainerbattle_single TRAINER_HIDDEN_OAK_2, HidingOak_Text_NewlyFoundOak, HidingOak_Text_DefeatedOak, HidingOak_EventScript_DefeatedOak, NO_MUSIC
    msgbox HidingOak_Text_PreviouslyFoundOak, MSGBOX_NPC
	msgbox HidingOak_Text_SecretPhrase_2, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_3::
    trainerbattle_single TRAINER_HIDDEN_OAK_3, HidingOak_Text_NewlyFoundOak, HidingOak_Text_DefeatedOak, HidingOak_EventScript_DefeatedOak, NO_MUSIC
    msgbox HidingOak_Text_PreviouslyFoundOak, MSGBOX_NPC
	msgbox HidingOak_Text_SecretPhrase_3, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_4::
    trainerbattle_single TRAINER_HIDDEN_OAK_4, HidingOak_Text_NewlyFoundOak, HidingOak_Text_DefeatedOak, HidingOak_EventScript_DefeatedOak, NO_MUSIC
    msgbox HidingOak_Text_PreviouslyFoundOak, MSGBOX_NPC
	msgbox HidingOak_Text_SecretPhrase_4, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_5::
    trainerbattle_single TRAINER_HIDDEN_OAK_5, HidingOak_Text_NewlyFoundOak, HidingOak_Text_DefeatedOak, HidingOak_EventScript_DefeatedOak, NO_MUSIC
    msgbox HidingOak_Text_PreviouslyFoundOak, MSGBOX_NPC
	msgbox HidingOak_Text_SecretPhrase_5, MSGBOX_NPC
	end
