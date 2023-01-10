/*#include "features.hpp"
#include "../../sdk/sdk.hpp"

void Features::BarrelLines::render() {
    if (!CONFIGBOOL("Visuals>Barrel>Enabled") || !Globals::localPlayer || !Globals::localPlayer->isAlive()) {
        return;
    }

    Vector barrelStart, barrelEnd;
    Vector ViewDir = angleVectors(Globals::localPlayer->aimPunchAngle());
    CTraceFilter filter;
    filter.pSkip = Globals::localPlayer;

    barrelStart = Globals::localPlayer->getBonePosition(8);
    barrelEnd = barrelStart;

    Ray_t ray;
    ray.Init(barrelStart, barrelStart + ViewDir * 3000);
    trace_t tr;
    Interfaces::trace->TraceRay(ray, MASK_SHOT | CONTENTS_GRATE, &filter, &tr);

    if (tr.fraction != 1.0f) {
        barrelEnd = tr.endpos;
    }

    drawLine(barrelStart.x, barrelStart.y, barrelEnd.x, barrelEnd.y, COLORCODE(255, 0, 0, 255));
}
*/