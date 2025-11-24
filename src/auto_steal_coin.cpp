// Add this script to skill.cpp right below Gank (RG_SNATCHER) script


// Auto steal coin when in Rogue Spirit state [wrywndp]
if (sd->sc.getSCE(SC_SPIRIT) && sd->sc.getSCE(SC_SPIRIT)->val2 == SL_ROGUE) {
	if (dstmd && sd->status.weapon != W_BOW &&
		(skill = pc_checkskill(sd, RG_SNATCHER)) > 0 &&
		(skill * 15 + 55) + pc_checkskill(sd, RG_STEALCOIN) * 10 > rnd() % 1000) {
		if (pc_steal_coin(sd, bl))
			clif_skill_nodamage(src, *bl, RG_STEALCOIN, skill);
		else
			clif_skill_fail(*sd, RG_SNATCHER);
	}
}