#include "../../stdafx.h"
#include "IniReader.h"
#include "IniWriter.h"

namespace Config
{
	char* colornames(int col)
	{
		switch (col)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "G";
			break;
		case 2:
			return "B";
			break;
		}
	}
	void Read(char* name)
	{
		static TCHAR path[MAX_PATH];
		std::string folder, file;
		if (strlen(name) > 0)
		{
			if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path)))
			{
				folder = std::string(path) + strenc("\\frosty.pw\\");
				file = std::string(path) + strenc("\\frosty.pw\\") + std::string(name) + strenc(".frosty");
			}
		}
		else
		{
			if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path)))
			{
				folder = std::string(path) + strenc("\\frosty.pw\\");
				file = std::string(path) + strenc("\\frosty.pw\\config.frosty");
			}
		}

		CIniReader reader(file.c_str());



		//	Options::SkinChanger::EnabledKnife = reader.ReadBoolean("SkinChanger"), "|EnabledKnife"), false);
		//	Options::SkinChanger::EnabledGlove = reader.ReadBoolean("SkinChanger"), "|EnabledGlove"), false);
		//	Options::SkinChanger::Knife = reader.ReadInteger("SkinChanger"), "|Knife"), 3);
		//	Options::SkinChanger::Glove = reader.ReadInteger("SkinChanger"), "|Glove"), 5);
		//	Options::SkinChanger::GloveSkin = reader.ReadInteger("SkinChanger"), "|GloveSkin"), 0);

		//Ragebot
		/*ClientVars.Rage.Enabled = reader.ReadBoolean("Ragebot", "Active", ClientVars.Rage.Enabled);
		ClientVars.Rage.Autofire = reader.ReadBoolean("Ragebot", "AutoShoot", ClientVars.Rage.Autofire);
		ClientVars.Rage.Autopistol = reader.ReadBoolean("Ragebot", "AutoPistol", ClientVars.Rage.Autopistol);
		ClientVars.Rage.Autoscope = reader.ReadBoolean("Ragebot", "AutoScope", ClientVars.Rage.Autoscope);
		ClientVars.Rage.autoduck = reader.ReadBoolean("Ragebot", "AutoDuck", ClientVars.Rage.autoduck);
		ClientVars.Rage.aimstep = reader.ReadBoolean("Ragebot", "Aimstep", ClientVars.Rage.aimstep);
		ClientVars.Rage.pSilent = reader.ReadBoolean("Ragebot", "pSilent", ClientVars.Rage.pSilent);
		ClientVars.Rage.Lagfix = reader.ReadBoolean("Ragebot", "PosAdjust", ClientVars.Rage.Lagfix);
		ClientVars.Rage.Resolver = reader.ReadBoolean("Ragebot", "Resolver", ClientVars.Rage.Resolver);
		ClientVars.Rage.Hitbox = reader.ReadInteger("Ragebot", "Hitbox", ClientVars.Rage.Hitbox);
		ClientVars.Rage.Hitscan = reader.ReadInteger("Ragebot", "Hitscan", ClientVars.Rage.Hitscan);
		ClientVars.Rage.Hitchance = reader.ReadInteger("Ragebot", "Hitchance", ClientVars.Rage.Hitchance);
		ClientVars.Rage.MinDmg = reader.ReadInteger("Ragebot", "MinDmg", ClientVars.Rage.MinDmg);
		ClientVars.Rage.MinDmg = reader.ReadInteger("Ragebot", "MinDmg", ClientVars.Rage.MinDmg);
		ClientVars.Rage.Baim = reader.ReadInteger("Ragebot", "Baim", ClientVars.Rage.Baim);

		//AntiAims
		ClientVars.AA.AntiAim = reader.ReadBoolean("AntiAim", "Enable AntiAim", ClientVars.AA.AntiAim);
		ClientVars.AA.gPitch = reader.ReadInteger("AntiAim", "gStanding Pitch", ClientVars.AA.gPitch);
		ClientVars.AA.gYaw = reader.ReadInteger("AntiAim", "gStanding Yaw", ClientVars.AA.gYaw);
		ClientVars.AA.gAtTargets = reader.ReadInteger("AntiAim", "gYaw At Target", ClientVars.AA.gAtTargets);
		ClientVars.AA.gFakeYaw = reader.ReadInteger("AntiAim", "gStanding FakeYaw", ClientVars.AA.gFakeYaw);
		ClientVars.AA.gAtTargetsFake = reader.ReadInteger("AntiAim", "gFakeYaw At Target", ClientVars.AA.gAtTargetsFake);

		ClientVars.AA.mPitch = reader.ReadInteger("AntiAim", "mStanding Pitch", ClientVars.AA.mPitch);
		ClientVars.AA.mYaw = reader.ReadInteger("AntiAim", "mStanding Yaw", ClientVars.AA.mYaw);
		ClientVars.AA.mAtTargets = reader.ReadInteger("AntiAim", "mYaw At Target", ClientVars.AA.mAtTargets);
		ClientVars.AA.mFakeYaw = reader.ReadInteger("AntiAim", "mStanding FakeYaw", ClientVars.AA.mFakeYaw);
		ClientVars.AA.mAtTargetsFake = reader.ReadInteger("AntiAim", "mFakeYaw At Target", ClientVars.AA.mAtTargetsFake);

		ClientVars.AA.aPitch = reader.ReadInteger("AntiAim", "aStanding Pitch", ClientVars.AA.aPitch);
		ClientVars.AA.aYaw = reader.ReadInteger("AntiAim", "aStanding Yaw", ClientVars.AA.aYaw);
		ClientVars.AA.aAtTargets = reader.ReadInteger("AntiAim", "aYaw At Target", ClientVars.AA.aAtTargets);
		ClientVars.AA.aFakeYaw = reader.ReadInteger("AntiAim", "aStanding FakeYaw", ClientVars.AA.aFakeYaw);
		ClientVars.AA.aAtTargetsFake = reader.ReadInteger("AntiAim", "aFakeYaw At Target", ClientVars.AA.aAtTargetsFake);

		ClientVars.AA.Edge = reader.ReadBoolean("AntiAim", "Enable WallDetect", ClientVars.AA.Edge);
		ClientVars.AA.wPitch = reader.ReadInteger("AntiAim", "wEdge Pitch", ClientVars.AA.wPitch);
		ClientVars.AA.wYaw = reader.ReadInteger("AntiAim", "wEdge Yaw", ClientVars.AA.wYaw);
		ClientVars.AA.wAtTargets = reader.ReadInteger("AntiAim", "wYaw At Target", ClientVars.AA.wAtTargets);
		ClientVars.AA.wFakeYaw = reader.ReadInteger("AntiAim", "wEdge FakeYaw", ClientVars.AA.wFakeYaw);
		ClientVars.AA.wAtTargetsFake = reader.ReadInteger("AntiAim", "wFakeYaw At Target", ClientVars.AA.wAtTargetsFake);

		//Legitbot
		ClientVars.Legit.Enabled = reader.ReadBoolean("Legitbot", "Active", ClientVars.Legit.Enabled);
		ClientVars.Legit.AimKey = reader.ReadInteger("Legitbot", "AimKey", ClientVars.Legit.AimKey);
		ClientVars.Legit.FOV = reader.ReadFloat("Legitbot", "FoV", ClientVars.Legit.FOV);
		ClientVars.Legit.Bone = reader.ReadInteger("Legitbot", "Bone", ClientVars.Legit.Bone);
		ClientVars.Legit.selection = reader.ReadInteger("Legitbot", "Selection", ClientVars.Legit.selection);
		ClientVars.Legit.Smooth = reader.ReadFloat("Legitbot", "Smoothness", ClientVars.Legit.Smooth);
		ClientVars.Legit.RCSsmooth = reader.ReadFloat("Legitbot", "RCSSmoothness", ClientVars.Legit.RCSsmooth);
		ClientVars.Legit.RCS = reader.ReadBoolean("Legitbot", "RecoilControl", ClientVars.Legit.RCS);
		ClientVars.Legit.RCSx = reader.ReadInteger("Legitbot", "RecoilX", ClientVars.Legit.RCSx);
		ClientVars.Legit.RCSy = reader.ReadInteger("Legitbot", "RecoilY", ClientVars.Legit.RCSy);
		ClientVars.Legit.StandaloneRCS = reader.ReadBoolean("Legitbot", "StandaloneRCS", ClientVars.Legit.StandaloneRCS);
		ClientVars.Legit.ignorejump = reader.ReadBoolean("Legitbot", "IgnoreJump", ClientVars.Legit.ignorejump);

		//Triggerbot
		ClientVars.Trigger.Enabled = reader.ReadBoolean("Triggerbot", "Active", ClientVars.Trigger.Enabled);
		ClientVars.Trigger.AutoFire = reader.ReadBoolean("Triggerbot", "AutoShoot", ClientVars.Trigger.AutoFire);
		ClientVars.Trigger.Enabled = reader.ReadBoolean("Triggerbot", "Active", ClientVars.Trigger.Enabled);
		ClientVars.Trigger.Key = reader.ReadInteger("Triggerbot", "TriggerKey", ClientVars.Trigger.Key);
		ClientVars.Trigger.HitChance = reader.ReadBoolean("Triggerbot", "Hitchance", ClientVars.Trigger.HitChance);
		ClientVars.Trigger.HitChanceAmt = reader.ReadFloat("Triggerbot", "HitchanceAmount", ClientVars.Trigger.HitChanceAmt);
		ClientVars.Trigger.Filter.Head = reader.ReadBoolean("Triggerbot", "TriggerHead", ClientVars.Trigger.Filter.Head);
		ClientVars.Trigger.Filter.Chest = reader.ReadBoolean("Triggerbot", "TriggerChest", ClientVars.Trigger.Filter.Chest);
		ClientVars.Trigger.Filter.Arms = reader.ReadBoolean("Triggerbot", "TriggerArms", ClientVars.Trigger.Filter.Arms);
		ClientVars.Trigger.Filter.Legs = reader.ReadBoolean("Triggerbot", "TriggerLegs", ClientVars.Trigger.Filter.Legs);
		ClientVars.Trigger.Filter.Stomach = reader.ReadBoolean("Triggerbot", "TriggerStomach", ClientVars.Trigger.Filter.Stomach);
		ClientVars.Trigger.Filter.Friendly = reader.ReadBoolean("Triggerbot", "TriggerFriendly", ClientVars.Trigger.Filter.Friendly);

		//Esp
		ClientVars.Vis.Droppedguns = reader.ReadBoolean("ESP", "DroppedWeapons", ClientVars.Vis.Droppedguns);
		ClientVars.Vis.Bomb = reader.ReadBoolean("ESP", "BombEsp", ClientVars.Vis.Bomb);
		ClientVars.Vis.Grenades = reader.ReadBoolean("ESP", "Grenades", ClientVars.Vis.Grenades);
		ClientVars.Vis.NadePred = reader.ReadBoolean("ESP", "GrenadePrediction", ClientVars.Vis.NadePred);
		ClientVars.Vis.Xhair = reader.ReadBoolean("ESP", "Crosshair", ClientVars.Vis.Xhair);
		ClientVars.Vis.Recoilxhair = reader.ReadBoolean("ESP", "RecoilCrosshair", ClientVars.Vis.Recoilxhair);
		ClientVars.Vis.LBYIndicator = reader.ReadBoolean("ESP", "LBYIndicator", ClientVars.Vis.LBYIndicator);
		ClientVars.Vis.Flashed = reader.ReadBoolean("ESP", "Vulnerable", ClientVars.Vis.Flashed);
		ClientVars.Vis.SteamID = reader.ReadBoolean("ESP", "SteamID", ClientVars.Vis.SteamID);
		ClientVars.Vis.AimLine = reader.ReadBoolean("ESP", "AimLines", ClientVars.Vis.AimLine);
		ClientVars.Vis.Showteam = reader.ReadBoolean("ESP", "TeamESP", ClientVars.Vis.Showteam);
		ClientVars.Vis.BoundingBox = reader.ReadBoolean("ESP", "BoxESP", ClientVars.Vis.BoundingBox);
		ClientVars.Vis.Box = reader.ReadInteger("ESP", "BoxType", ClientVars.Vis.Box);
		ClientVars.Vis.Skeleton = reader.ReadBoolean("ESP", "SkeletonESP", ClientVars.Vis.Skeleton);
		ClientVars.Vis.Name = reader.ReadBoolean("ESP", "NameESP", ClientVars.Vis.Name);
		ClientVars.Vis.Weapon = reader.ReadBoolean("ESP", "WeaponESP", ClientVars.Vis.Weapon);
		ClientVars.Vis.wpnmode = reader.ReadInteger("ESP", "WeaponType", ClientVars.Vis.wpnmode);
		ClientVars.Vis.Armor = reader.ReadBoolean("ESP", "ArmorESP", ClientVars.Vis.Armor);
		ClientVars.Vis.Health = reader.ReadBoolean("ESP", "HealthESP", ClientVars.Vis.Health);
		ClientVars.Vis.Money = reader.ReadBoolean("ESP", "MoneyESP", ClientVars.Vis.Money);
		ClientVars.Vis.Callout = reader.ReadBoolean("ESP", "CalloutESP", ClientVars.Vis.Callout);
		ClientVars.Vis.Barrel = reader.ReadBoolean("ESP", "BarrelESP", ClientVars.Vis.Barrel);
		ClientVars.Vis.BarrelAmt = reader.ReadFloat("ESP", "BarrelESPAmt", ClientVars.Vis.BarrelAmt);

		//Render
		ClientVars.Vis.FOV = reader.ReadFloat("Render", "FieldOfView", ClientVars.Vis.FOV);
		ClientVars.Vis.Thirdperson = reader.ReadFloat("Render", "Thirdperson", ClientVars.Vis.Thirdperson);
		ClientVars.Vis.NoVisRecoil = reader.ReadBoolean("Render", "NoVisRecoil", ClientVars.Vis.NoVisRecoil);
		ClientVars.Vis.NoSmoke = reader.ReadBoolean("Render", "NoSmoke", ClientVars.Vis.NoSmoke);
		ClientVars.Vis.NoFlash = reader.ReadBoolean("Render", "NoFlash", ClientVars.Vis.NoFlash);
		ClientVars.Vis.NoScope = reader.ReadBoolean("Render", "NoScope", ClientVars.Vis.NoScope);
		ClientVars.Vis.Chams = reader.ReadBoolean("Render", "Chams", ClientVars.Vis.Chams);
		ClientVars.Vis.matierial = reader.ReadInteger("Render", "ChamsMaterial", ClientVars.Vis.matierial);
		ClientVars.Vis.Teamchams = reader.ReadBoolean("Render", "TeamChams", ClientVars.Vis.Teamchams);
		ClientVars.Vis.Visiblechams = reader.ReadBoolean("Render", "XQZChams", ClientVars.Vis.Visiblechams);
		ClientVars.Vis.Chamweapon = reader.ReadBoolean("Render", "WeaponChams", ClientVars.Vis.Chamweapon);
		ClientVars.Vis.radrenable = reader.ReadBoolean("Render", "RadarEnable", ClientVars.Vis.radrenable);
		ClientVars.Vis.enemyonlyradr = reader.ReadBoolean("Render", "EnemyOnlyRadar", ClientVars.Vis.enemyonlyradr);
		ClientVars.Vis.visibleonlyradr = reader.ReadBoolean("Render", "VisOnlyRadar", ClientVars.Vis.visibleonlyradr);
		ClientVars.Vis.smokecheckradr = reader.ReadBoolean("Render", "SmokeCheckRadar", ClientVars.Vis.smokecheckradr);
		ClientVars.Vis.radralpha = reader.ReadInteger("Render", "RadarAlpha", ClientVars.Vis.radralpha);
		ClientVars.Vis.radrsize = reader.ReadInteger("Render", "RadarSize", ClientVars.Vis.radrsize);
		ClientVars.Vis.radrzoom = reader.ReadFloat("Render", "RadarZoom", ClientVars.Vis.radrzoom);
		ClientVars.Vis.radrtype = reader.ReadInteger("Render", "RadarDrawStyle", ClientVars.Vis.radrtype);
		ClientVars.Vis.Glow = reader.ReadBoolean("Render", "Glow", ClientVars.Vis.Glow);
		ClientVars.Vis.glowamt = reader.ReadInteger("Render", "GlowAlpha", ClientVars.Vis.glowamt);
		ClientVars.Vis.GlowTeam = reader.ReadBoolean("Render", "GlowTeam", ClientVars.Vis.GlowTeam);
		ClientVars.Vis.Weaponglow = reader.ReadBoolean("Render", "GlowWeapon", ClientVars.Vis.Weaponglow);
		ClientVars.Vis.C4glow = reader.ReadBoolean("Render", "GlowBomb", ClientVars.Vis.C4glow);
		ClientVars.Vis.DLight = reader.ReadBoolean("Render", "DLight", ClientVars.Vis.DLight);
		ClientVars.Vis.DLightteam = reader.ReadBoolean("Render", "DLightTeam", ClientVars.Vis.DLightteam);
		ClientVars.Vis.ELight = reader.ReadBoolean("Render", "ELight", ClientVars.Vis.ELight);
		ClientVars.Vis.handcham = reader.ReadBoolean("Render", "HandChams", ClientVars.Vis.handcham);
		ClientVars.Vis.handmat = reader.ReadInteger("Render", "HandMaterial", ClientVars.Vis.handmat);
		ClientVars.Vis.weaponviewcham = reader.ReadBoolean("Render", "WeaponViewChams", ClientVars.Vis.weaponviewcham);
		ClientVars.Vis.weaponmat = reader.ReadBoolean("Render", "WeaponViewMaterial", ClientVars.Vis.weaponmat);

		//Misc
		ClientVars.Misc.Antiuntrustedproxy = reader.ReadBoolean("Misc", "AntiUntrust", ClientVars.Misc.Antiuntrustedproxy);
		ClientVars.Misc.Bhop = reader.ReadBoolean("Misc", "Bhop", ClientVars.Misc.Bhop);
		ClientVars.Misc.Strafe = reader.ReadBoolean("Misc", "AutoStrafe", ClientVars.Misc.Strafe);
		ClientVars.Misc.Strafetype = reader.ReadInteger("Misc", "StrafeType", ClientVars.Misc.Strafetype);
		ClientVars.Misc.CircleStrafe = reader.ReadBoolean("Misc", "CStrafe", ClientVars.Misc.CircleStrafe);
		ClientVars.Misc.CStrafeKey = reader.ReadInteger("Misc", "CStrafeKey", ClientVars.Misc.CStrafeKey);
		ClientVars.Misc.RankReveal = reader.ReadBoolean("Misc", "RankRevealer", ClientVars.Misc.RankReveal);
		ClientVars.Misc.AutoAccept = reader.ReadBoolean("Misc", "AutoAccept", ClientVars.Misc.AutoAccept);
		ClientVars.Misc.FakeLagType = reader.ReadInteger("Misc", "FakeLagType", ClientVars.Misc.FakeLagType);
		ClientVars.Misc.Knifebot = reader.ReadBoolean("Misc", "Knifebot", ClientVars.Misc.Knifebot);

		for (int i = 0; i < 3; i++)
		{
			char* section = colornames(i);
			ClientVars.Col.TeamESP[i] = reader.ReadFloat(section, "Team ESP", ClientVars.Col.TeamESP[i]);
			ClientVars.Col.EnemyESP[i] = reader.ReadFloat(section, "Enemy ESP", ClientVars.Col.EnemyESP[i]);
			ClientVars.Col.TeamDLights[i] = reader.ReadFloat(section, "Team DLights", ClientVars.Col.TeamDLights[i]);
			ClientVars.Col.EnemyDLights[i] = reader.ReadFloat(section, "Enemy DLights", ClientVars.Col.EnemyDLights[i]);
			ClientVars.Col.EnemyGlow[i] = reader.ReadFloat(section, "Enemy Glow", ClientVars.Col.EnemyGlow[i]);
			ClientVars.Col.TeamGlow[i] = reader.ReadFloat(section, "Team Glow", ClientVars.Col.TeamGlow[i]);
			ClientVars.Col.WeaponGlow[i] = reader.ReadFloat(section, "Weapon Glow", ClientVars.Col.WeaponGlow[i]);
			ClientVars.Col.C4glow[i] = reader.ReadFloat(section, "C4 Glow", ClientVars.Col.C4glow[i]);
			ClientVars.Col.EnemyChamsVis[i] = reader.ReadFloat(section, "Enemy Visible Chams", ClientVars.Col.EnemyChamsVis[i]);
			ClientVars.Col.EnemyChamsNVis[i] = reader.ReadFloat(section, "Enemy Invisible Chams", ClientVars.Col.EnemyChamsNVis[i]);
			ClientVars.Col.TeamChamsVis[i] = reader.ReadFloat(section, "Team Visible Chams", ClientVars.Col.TeamChamsVis[i]);
			ClientVars.Col.TeamChamsNVis[i] = reader.ReadFloat(section, "Team Invisible Chams", ClientVars.Col.TeamChamsNVis[i]);
			ClientVars.Col.TeamOutline[i] = reader.ReadFloat(section, "Team Outline", ClientVars.Col.TeamOutline[i]);
			ClientVars.Col.EnemyOutline[i] = reader.ReadFloat(section, "Enemy Outline", ClientVars.Col.EnemyOutline[i]);
			ClientVars.Col.WeaponCham[i] = reader.ReadFloat(section, "Weapon Cham", ClientVars.Col.WeaponCham[i]);
		}
		for (int i = 1; i < 520; i++)
		{
			char* section = Misc::GetGunNameByID(i);
			if (strcmp(section, "") == 0)
				continue;

			ClientVars.W[i].ChangerEnabled = reader.ReadBoolean(section, "ChangerEnabled", ClientVars.W[i].ChangerEnabled);
			ClientVars.W[i].ChangerName[32] = *reader.ReadString(section, "ChangerName", ClientVars.W[i].ChangerName);
			ClientVars.W[i].ChangerSeed = reader.ReadInteger(section, "ChangerSeed", ClientVars.W[i].ChangerSeed);
			ClientVars.W[i].ChangerSkin = reader.ReadInteger(section, "ChangerSkin", ClientVars.W[i].ChangerSkin);
			ClientVars.W[i].ChangerStatTrak = reader.ReadInteger(section, "ChangerStatTrak", ClientVars.W[i].ChangerStatTrak);
			ClientVars.W[i].ChangerWear = reader.ReadFloat(section, "ChangerWear", ClientVars.W[i].ChangerWear);
		}*/
	}

	void Save(char* name)
	{
		static TCHAR path[MAX_PATH];
		std::string folder, file;
		if (strlen(name) > 0)
		{
			if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path)))
			{
				folder = std::string(path) + strenc("\\frosty.pw\\");
				file = std::string(path) + strenc("\\frosty.pw\\") + std::string(name) + strenc(".frosty");
			}
		}
		else
		{
			if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path)))
			{
				folder = std::string(path) + strenc("\\frosty.pw\\");
				file = std::string(path) + strenc("\\frosty.pw\\config.frosty");
			}
		}

		CreateDirectory(folder.c_str(), NULL);

		CIniWriter writer(file.c_str());




		//	writer.WriteBoolean(strenc("SkinChanger"), strenc("|EnabledKnife"), Options::SkinChanger::EnabledKnife);
		//	writer.WriteBoolean(strenc("SkinChanger"), strenc("|EnabledGlove"), Options::SkinChanger::EnabledGlove);
		//	writer.WriteInteger(strenc("SkinChanger"), strenc("|Knife"), Options::SkinChanger::Knife);
		//	writer.WriteInteger(strenc("SkinChanger"), strenc("|Glove"), Options::SkinChanger::Glove);
		//	writer.WriteInteger(strenc("SkinChanger"), strenc("|GloveSkin"), Options::SkinChanger::GloveSkin);

		//Ragebot
		/*writer.WriteBoolean("Ragebot", "Active", ClientVars.Rage.Enabled);
		writer.WriteBoolean("Ragebot", "AutoShoot", ClientVars.Rage.Autofire);
		writer.WriteBoolean("Ragebot", "AutoPistol", ClientVars.Rage.Autopistol);
		writer.WriteBoolean("Ragebot", "AutoScope", ClientVars.Rage.Autoscope);
		writer.WriteBoolean("Ragebot", "AutoDuck", ClientVars.Rage.autoduck);
		writer.WriteBoolean("Ragebot", "Aimstep", ClientVars.Rage.aimstep);
		writer.WriteBoolean("Ragebot", "pSilent", ClientVars.Rage.pSilent);
		writer.WriteBoolean("Ragebot", "PosAdjust", ClientVars.Rage.Lagfix);
		writer.WriteBoolean("Ragebot", "Resolver", ClientVars.Rage.Resolver);
		writer.WriteInteger("Ragebot", "Hitbox", ClientVars.Rage.Hitbox);
		writer.WriteInteger("Ragebot", "Hitscan", ClientVars.Rage.Hitscan);
		writer.WriteInteger("Ragebot", "Hitchance", ClientVars.Rage.Hitchance);
		writer.WriteInteger("Ragebot", "MinDmg", ClientVars.Rage.MinDmg);
		writer.WriteInteger("Ragebot", "MinDmg", ClientVars.Rage.MinDmg);
		writer.WriteInteger("Ragebot", "Baim", ClientVars.Rage.Baim);

		//AntiAims
		writer.WriteBoolean("AntiAim", "Enable AntiAim", ClientVars.AA.AntiAim);
		writer.WriteInteger("AntiAim", "gStanding Pitch", ClientVars.AA.gPitch);
		writer.WriteInteger("AntiAim", "gStanding Yaw", ClientVars.AA.gYaw);
		writer.WriteInteger("AntiAim", "gYaw At Target", ClientVars.AA.gAtTargets);
		writer.WriteInteger("AntiAim", "gStanding FakeYaw", ClientVars.AA.gFakeYaw);
		writer.WriteInteger("AntiAim", "gFakeYaw At Target", ClientVars.AA.gAtTargetsFake);

		writer.WriteInteger("AntiAim", "mStanding Pitch", ClientVars.AA.mPitch);
		writer.WriteInteger("AntiAim", "mStanding Yaw", ClientVars.AA.mYaw);
		writer.WriteInteger("AntiAim", "mYaw At Target", ClientVars.AA.mAtTargets);
		writer.WriteInteger("AntiAim", "mStanding FakeYaw", ClientVars.AA.mFakeYaw);
		writer.WriteInteger("AntiAim", "mFakeYaw At Target", ClientVars.AA.mAtTargetsFake);

		writer.WriteInteger("AntiAim", "aStanding Pitch", ClientVars.AA.aPitch);
		writer.WriteInteger("AntiAim", "aStanding Yaw", ClientVars.AA.aYaw);
		writer.WriteInteger("AntiAim", "aYaw At Target", ClientVars.AA.aAtTargets);
		writer.WriteInteger("AntiAim", "aStanding FakeYaw", ClientVars.AA.aFakeYaw);
		writer.WriteInteger("AntiAim", "aFakeYaw At Target", ClientVars.AA.aAtTargetsFake);

		writer.WriteBoolean("AntiAim", "Enable WallDetect", ClientVars.AA.Edge);
		writer.WriteInteger("AntiAim", "wEdge Pitch", ClientVars.AA.wPitch);
		writer.WriteInteger("AntiAim", "wEdge Yaw", ClientVars.AA.wYaw);
		writer.WriteInteger("AntiAim", "wYaw At Target", ClientVars.AA.wAtTargets);
		writer.WriteInteger("AntiAim", "wEdge FakeYaw", ClientVars.AA.wFakeYaw);
		writer.WriteInteger("AntiAim", "wFakeYaw At Target", ClientVars.AA.wAtTargetsFake);

		//Legitbot
		writer.WriteBoolean("Legitbot", "Active", ClientVars.Legit.Enabled);
		writer.WriteInteger("Legitbot", "AimKey", ClientVars.Legit.AimKey);
		writer.WriteFloat("Legitbot", "FoV", ClientVars.Legit.FOV);
		writer.WriteInteger("Legitbot", "Bone", ClientVars.Legit.Bone);
		writer.WriteInteger("Legitbot", "Selection", ClientVars.Legit.selection);
		writer.WriteFloat("Legitbot", "Smoothness", ClientVars.Legit.Smooth);
		writer.WriteFloat("Legitbot", "RCSSmoothness", ClientVars.Legit.RCSsmooth);
		writer.WriteBoolean("Legitbot", "RecoilControl", ClientVars.Legit.RCS);
		writer.WriteInteger("Legitbot", "RecoilX", ClientVars.Legit.RCSx);
		writer.WriteInteger("Legitbot", "RecoilY", ClientVars.Legit.RCSy);
		writer.WriteBoolean("Legitbot", "StandaloneRCS", ClientVars.Legit.StandaloneRCS);
		writer.WriteBoolean("Legitbot", "IgnoreJump", ClientVars.Legit.ignorejump);

		//Triggerbot
		writer.WriteBoolean("Triggerbot", "Active", ClientVars.Trigger.Enabled);
		writer.WriteBoolean("Triggerbot", "AutoShoot", ClientVars.Trigger.AutoFire);
		writer.WriteBoolean("Triggerbot", "Active", ClientVars.Trigger.Enabled);
		writer.WriteInteger("Triggerbot", "TriggerKey", ClientVars.Trigger.Key);
		writer.WriteBoolean("Triggerbot", "Hitchance", ClientVars.Trigger.HitChance);
		writer.WriteFloat("Triggerbot", "HitchanceAmount", ClientVars.Trigger.HitChanceAmt);
		writer.WriteBoolean("Triggerbot", "TriggerHead", ClientVars.Trigger.Filter.Head);
		writer.WriteBoolean("Triggerbot", "TriggerChest", ClientVars.Trigger.Filter.Chest);
		writer.WriteBoolean("Triggerbot", "TriggerArms", ClientVars.Trigger.Filter.Arms);
		writer.WriteBoolean("Triggerbot", "TriggerLegs", ClientVars.Trigger.Filter.Legs);
		writer.WriteBoolean("Triggerbot", "TriggerStomach", ClientVars.Trigger.Filter.Stomach);
		writer.WriteBoolean("Triggerbot", "TriggerFriendly", ClientVars.Trigger.Filter.Friendly);

		//Esp
		writer.WriteBoolean("ESP", "DroppedWeapons", ClientVars.Vis.Droppedguns);
		writer.WriteBoolean("ESP", "BombEsp", ClientVars.Vis.Bomb);
		writer.WriteBoolean("ESP", "Grenades", ClientVars.Vis.Grenades);
		writer.WriteBoolean("ESP", "GrenadePrediction", ClientVars.Vis.NadePred);
		writer.WriteBoolean("ESP", "Crosshair", ClientVars.Vis.Xhair);
		writer.WriteBoolean("ESP", "RecoilCrosshair", ClientVars.Vis.Recoilxhair);
		writer.WriteBoolean("ESP", "LBYIndicator", ClientVars.Vis.LBYIndicator);
		writer.WriteBoolean("ESP", "Vulnerable", ClientVars.Vis.Flashed);
		writer.WriteBoolean("ESP", "SteamID", ClientVars.Vis.SteamID);
		writer.WriteBoolean("ESP", "AimLines", ClientVars.Vis.AimLine);
		writer.WriteBoolean("ESP", "TeamESP", ClientVars.Vis.Showteam);
		writer.WriteBoolean("ESP", "BoxESP", ClientVars.Vis.BoundingBox);
		writer.WriteInteger("ESP", "BoxType", ClientVars.Vis.Box);
		writer.WriteBoolean("ESP", "SkeletonESP", ClientVars.Vis.Skeleton);
		writer.WriteBoolean("ESP", "NameESP", ClientVars.Vis.Name);
		writer.WriteBoolean("ESP", "WeaponESP", ClientVars.Vis.Weapon);
		writer.WriteInteger("ESP", "WeaponType", ClientVars.Vis.wpnmode);
		writer.WriteBoolean("ESP", "ArmorESP", ClientVars.Vis.Armor);
		writer.WriteBoolean("ESP", "HealthESP", ClientVars.Vis.Health);
		writer.WriteBoolean("ESP", "MoneyESP", ClientVars.Vis.Money);
		writer.WriteBoolean("ESP", "CalloutESP", ClientVars.Vis.Callout);
		writer.WriteBoolean("ESP", "BarrelESP", ClientVars.Vis.Barrel);
		writer.WriteFloat("ESP", "BarrelESPAmt", ClientVars.Vis.BarrelAmt);

		//Render
		writer.WriteFloat("Render", "FieldOfView", ClientVars.Vis.FOV);
		writer.WriteFloat("Render", "Thirdperson", ClientVars.Vis.Thirdperson);
		writer.WriteBoolean("Render", "NoVisRecoil", ClientVars.Vis.NoVisRecoil);
		writer.WriteBoolean("Render", "NoSmoke", ClientVars.Vis.NoSmoke);
		writer.WriteBoolean("Render", "NoFlash", ClientVars.Vis.NoFlash);
		writer.WriteBoolean("Render", "NoScope", ClientVars.Vis.NoScope);
		writer.WriteBoolean("Render", "Chams", ClientVars.Vis.Chams);
		writer.WriteInteger("Render", "ChamsMaterial", ClientVars.Vis.matierial);
		writer.WriteBoolean("Render", "TeamChams", ClientVars.Vis.Teamchams);
		writer.WriteBoolean("Render", "XQZChams", ClientVars.Vis.Visiblechams);
		writer.WriteBoolean("Render", "WeaponChams", ClientVars.Vis.Chamweapon);
		writer.WriteBoolean("Render", "RadarEnable", ClientVars.Vis.radrenable);
		writer.WriteBoolean("Render", "EnemyOnlyRadar", ClientVars.Vis.enemyonlyradr);
		writer.WriteBoolean("Render", "VisOnlyRadar", ClientVars.Vis.visibleonlyradr);
		writer.WriteBoolean("Render", "SmokeCheckRadar", ClientVars.Vis.smokecheckradr);
		writer.WriteInteger("Render", "RadarAlpha", ClientVars.Vis.radralpha);
		writer.WriteInteger("Render", "RadarSize", ClientVars.Vis.radrsize);
		writer.WriteFloat("Render", "RadarZoom", ClientVars.Vis.radrzoom);
		writer.WriteInteger("Render", "RadarDrawStyle", ClientVars.Vis.radrtype);
		writer.WriteBoolean("Render", "Glow", ClientVars.Vis.Glow);
		writer.WriteInteger("Render", "GlowAlpha", ClientVars.Vis.glowamt);
		writer.WriteBoolean("Render", "GlowTeam", ClientVars.Vis.GlowTeam);
		writer.WriteBoolean("Render", "GlowWeapon", ClientVars.Vis.Weaponglow);
		writer.WriteBoolean("Render", "GlowBomb", ClientVars.Vis.C4glow);
		writer.WriteBoolean("Render", "DLight", ClientVars.Vis.DLight);
		writer.WriteBoolean("Render", "DLightTeam", ClientVars.Vis.DLightteam);
		writer.WriteBoolean("Render", "ELight", ClientVars.Vis.ELight);
		writer.WriteBoolean("Render", "HandChams", ClientVars.Vis.handcham);
		writer.WriteInteger("Render", "HandMaterial", ClientVars.Vis.handmat);
		writer.WriteBoolean("Render", "WeaponViewChams", ClientVars.Vis.weaponviewcham);
		writer.WriteBoolean("Render", "WeaponViewMaterial", ClientVars.Vis.weaponmat);

		//Misc
		writer.WriteBoolean("Misc", "AntiUntrust", ClientVars.Misc.Antiuntrustedproxy);
		writer.WriteBoolean("Misc", "Bhop", ClientVars.Misc.Bhop);
		writer.WriteBoolean("Misc", "AutoStrafe", ClientVars.Misc.Strafe);
		writer.WriteInteger("Misc", "StrafeType", ClientVars.Misc.Strafetype);
		writer.WriteBoolean("Misc", "CStrafe", ClientVars.Misc.CircleStrafe);
		writer.WriteInteger("Misc", "CStrafeKey", ClientVars.Misc.CStrafeKey);
		writer.WriteBoolean("Misc", "RankRevealer", ClientVars.Misc.RankReveal);
		writer.WriteBoolean("Misc", "AutoAccept", ClientVars.Misc.AutoAccept);
		writer.WriteInteger("Misc", "FakeLagType", ClientVars.Misc.FakeLagType);
		writer.WriteBoolean("Misc", "Knifebot", ClientVars.Misc.Knifebot);

		for (int i = 0; i < 3; i++)
		{
			char* section = colornames(i);
			//Colors
			writer.WriteFloat(section, "Team ESP", ClientVars.Col.TeamESP[i]);
			writer.WriteFloat(section, "Enemy ESP", ClientVars.Col.EnemyESP[i]);
			writer.WriteFloat(section, "Team DLights", ClientVars.Col.TeamDLights[i]);
			writer.WriteFloat(section, "Enemy DLights", ClientVars.Col.EnemyDLights[i]);
			writer.WriteFloat(section, "Enemy Glow", ClientVars.Col.EnemyGlow[i]);
			writer.WriteFloat(section, "Team Glow", ClientVars.Col.TeamGlow[i]);
			writer.WriteFloat(section, "Weapon Glow", ClientVars.Col.WeaponGlow[i]);
			writer.WriteFloat(section, "C4 Glow", ClientVars.Col.C4glow[i]);
			writer.WriteFloat(section, "Enemy Visible Chams", ClientVars.Col.EnemyChamsVis[i]);
			writer.WriteFloat(section, "Enemy Invisible Chams", ClientVars.Col.EnemyChamsNVis[i]);
			writer.WriteFloat(section, "Team Visible Chams", ClientVars.Col.TeamChamsVis[i]);
			writer.WriteFloat(section, "Team Invisible Chams", ClientVars.Col.TeamChamsNVis[i]);
			writer.WriteFloat(section, "Team Outline", ClientVars.Col.TeamOutline[i]);
			writer.WriteFloat(section, "Enemy Outline", ClientVars.Col.EnemyOutline[i]);
			writer.WriteFloat(section, "Weapon Cham", ClientVars.Col.WeaponCham[i]);
		}

		for (int i = 1; i < 520; i++)
		{
			char* section = Misc::GetGunNameByID(i);
			if (strcmp(section, "") == 0)
				continue;




			writer.WriteBoolean(section, ("ChangerEnabled"), ClientVars.W[i].ChangerEnabled);
			writer.WriteInteger(section, ("ChangerSkin"), ClientVars.W[i].ChangerSkin);
			writer.WriteString(section, ("ChangerName"), ClientVars.W[i].ChangerName);
			writer.WriteInteger(section, ("ChangerStatTrak"), ClientVars.W[i].ChangerStatTrak);
			writer.WriteInteger(section, ("ChangerSeed"), ClientVars.W[i].ChangerSeed);
			writer.WriteFloat(section, ("ChangerWear"), ClientVars.W[i].ChangerWear);
		}*/
	}
}