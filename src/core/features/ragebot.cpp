#include "../../includes.hpp"
#include "features.hpp"

enum Hitbox {
    HEAD,
    CHEST
};

void Features::RageBot::createMove(CUserCmd* cmd) {
    if (Interfaces::engine->IsInGame() && Globals::localPlayer && Globals::localPlayer->health() > 0 && cmd->buttons & (1 << 0)) {
        Weapon *weapon = (Weapon *) Interfaces::entityList->GetClientEntity((uintptr_t)Globals::localPlayer->activeWeapon() & 0xFFF); // GetClientEntityFromHandle is being gay
        if (weapon) {
            float FOV = CONFIGINT("Rage>RageBot>Default>FOV")/10.f;

            float closestDelta = FLT_MAX;
            QAngle angleToClosestPlayer = {0, 0, 0};
            int hitboxes = CONFIGINT("Rage>RageBot>Default>Hitboxes");
            Hitbox targetHitbox;
                switch (hitboxes) {
                    case 0:
                        targetHitbox = HEAD;
                        break;
                    case 1:
                        targetHitbox = CHEST;
                        break;
                }
                hitboxes = CONFIGINT("Rage>RageBot>Pistol>Hitboxes");
                switch (hitboxes) {
                    case 0:
                        targetHitbox = HEAD;
                        break;
                    case 1:
                        targetHitbox = CHEST;
                        break;
                }
            // Enumerate over players and get angle to the closest player to crosshair
            for (int i = 1; i < Interfaces::globals->maxClients; i++) {
                Player* p = (Player*)Interfaces::entityList->GetClientEntity(i);
                if (p && p != Globals::localPlayer) {
                    if (p->health() > 0 && !p->dormant() && p->isEnemy()) {
                        matrix3x4_t boneMatrix[128];
                        if (p->getAnythingBones(boneMatrix)) {
                            Vector localPlayerEyePos = Globals::localPlayer->eyePos();
                            Vector targetBonePos;
                            if (targetHitbox == HEAD || targetHitbox == BOTH) {
                                targetBonePos = p->getBonePos(8); // Head
                            }
                            else if (targetHitbox == CHEST) {
                                targetBonePos = p->getBonePos(4); // Chest
                            }

                            if(CONFIGBOOL("Rage>RageBot>Default>ForceBaim")) {
                                if(p->health() <= CONFIGINT("Rage>RageBot>Default>ForceBaimValue")) {
                                    targetBonePos = p->getBonePos(0); // Pelvis
                                } else {
                                    targetBonePos = p->getBonePos(8); // Head
                                }
                            }

                            QAngle angleToCurrentPlayer = calcAngle(localPlayerEyePos, targetBonePos) - cmd->viewangles - Globals::localPlayer->aimPunch()*2
;
                            normalizeAngles(angleToCurrentPlayer);

                            if (angleToCurrentPlayer.Length() < closestDelta) {
                                closestDelta = angleToCurrentPlayer.Length();
                                angleToClosestPlayer = angleToCurrentPlayer;
                            }
                        }
                    }
                }
            }
            if (closestDelta < FOV) {
                cmd->viewangles += angleToClosestPlayer;
            }
        }
    }
}