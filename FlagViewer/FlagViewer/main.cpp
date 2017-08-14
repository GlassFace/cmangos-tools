#include <stdio.h>
#include <stdlib.h>

enum UnitFlags
{
    UNIT_FLAG_UNK_0                 = 0x00000001,
    UNIT_FLAG_NON_ATTACKABLE        = 0x00000002,           // not attackable
    UNIT_FLAG_NON_MOVING_DEPRECATED = 0x00000004,           // TODO: Needs research
    UNIT_FLAG_PLAYER_CONTROLLED     = 0x00000008,           // players, pets, totems, guardians, companions, charms, any units associated with players
    UNIT_FLAG_RENAME                = 0x00000010,
    UNIT_FLAG_PREPARATION           = 0x00000020,           // don't take reagents for spells with SPELL_ATTR_EX5_NO_REAGENT_WHILE_PREP
    UNIT_FLAG_UNK_6                 = 0x00000040,
    UNIT_FLAG_NOT_ATTACKABLE_1      = 0x00000080,           // ?? (UNIT_FLAG_PVP_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE - blue color target
    UNIT_FLAG_IMMUNE_TO_PLAYER      = 0x00000100,           // Target is immune to players
    UNIT_FLAG_IMMUNE_TO_NPC         = 0x00000200,           // makes you unable to attack everything. Almost identical to our "civilian"-term. Will ignore it's surroundings and not engage in combat unless "called upon" or engaged by another unit.
    UNIT_FLAG_LOOTING               = 0x00000400,           // loot animation
    UNIT_FLAG_PET_IN_COMBAT         = 0x00000800,           // in combat?, 2.0.8 Possibly Unkillable
    UNIT_FLAG_PVP                   = 0x00001000,
    UNIT_FLAG_SILENCED              = 0x00002000,           // silenced, 2.1.1
    UNIT_FLAG_PERSUADED             = 0x00004000,           // persuaded, 2.0.8
    UNIT_FLAG_SWIMMING              = 0x00008000,           // controls water swimming animation - TODO: confirm whether dynamic or static
    UNIT_FLAG_UNK_16                = 0x00010000,           // removes attackable icon, if on yourself, cannot assist self but can cast TARGET_SELF spells
    UNIT_FLAG_PACIFIED              = 0x00020000,
    UNIT_FLAG_STUNNED               = 0x00040000,           // stunned, 2.1.1
    UNIT_FLAG_IN_COMBAT             = 0x00080000,
    UNIT_FLAG_TAXI_FLIGHT           = 0x00100000,           // disable casting at client side spell not allowed by taxi flight (mounted?), probably used with 0x4 flag
    UNIT_FLAG_DISARMED              = 0x00200000,           // disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.
    UNIT_FLAG_CONFUSED              = 0x00400000,
    UNIT_FLAG_FLEEING               = 0x00800000,
    UNIT_FLAG_POSSESSED             = 0x01000000,           // remote control e.g. Eyes of the Beast: let master use melee attack, make unit unselectable via mouse for master in world (as if it was own character)
    UNIT_FLAG_NOT_SELECTABLE        = 0x02000000,
    UNIT_FLAG_SKINNABLE             = 0x04000000,
    UNIT_FLAG_MOUNT                 = 0x08000000,
    UNIT_FLAG_UNK_28                = 0x10000000,
    UNIT_FLAG_UNK_29                = 0x20000000,           // used in Feing Death spell
    UNIT_FLAG_SHEATHE               = 0x40000000
                                      // UNIT_FLAG_UNK_31              = 0x80000000           // no affect in 2.4.3
};

char* enumStrings[] =
{
    "UNIT_FLAG_UNK_0",
    "UNIT_FLAG_NON_ATTACKABLE",
    "UNIT_FLAG_NON_MOVING_DEPRECATED",
    "UNIT_FLAG_PLAYER_CONTROLLED",
    "UNIT_FLAG_RENAME",
    "UNIT_FLAG_PREPARATION",
    "UNIT_FLAG_UNK_6",
    "UNIT_FLAG_NOT_ATTACKABLE_1",
    "UNIT_FLAG_IMMUNE_TO_PLAYER",
    "UNIT_FLAG_IMMUNE_TO_NPC",
    "UNIT_FLAG_LOOTING",
    "UNIT_FLAG_PET_IN_COMBAT",
    "UNIT_FLAG_PVP",
    "UNIT_FLAG_SILENCED",
    "UNIT_FLAG_PERSUADED",
    "UNIT_FLAG_SWIMMING",
    "UNIT_FLAG_UNK_16",
    "UNIT_FLAG_PACIFIED",
    "UNIT_FLAG_STUNNED",
    "UNIT_FLAG_IN_COMBAT",
    "UNIT_FLAG_TAXI_FLIGHT",
    "UNIT_FLAG_DISARMED",
    "UNIT_FLAG_CONFUSED",
    "UNIT_FLAG_FLEEING",
    "UNIT_FLAG_POSSESSED",
    "UNIT_FLAG_NOT_SELECTABLE",
    "UNIT_FLAG_SKINNABLE",
    "UNIT_FLAG_MOUNT",
    "UNIT_FLAG_UNK_28",
    "UNIT_FLAG_UNK_29",
    "UNIT_FLAG_SHEATHE",
};

int main(int argc, char* argv[])
{
    long long flags = 1;
    scanf("%lld", &flags);
    while (flags)
    {
        for (int enumValue = UNIT_FLAG_UNK_0, i = 0; enumValue != UNIT_FLAG_SHEATHE; enumValue *=2, i++)
        {
            if (flags&enumValue)
                printf("%s\n",enumStrings[i]);
        }
        scanf("%lld", &flags);
    }
    return 0;
}