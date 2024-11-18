/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {"vazirmatn:size=13","vazirmatn:size=13","monospace:size=12","Font Awesome 6 Free:size=12","FuraMono Nerd Font:size=12"};
static const char dmenufont[]       = "vazirmatn:size=13";
static const char col_gray1[]       = "#000000"; /* bar color */
static const char col_gray2[]       = "#000000"; /* inactive window border */
static const char col_gray3[]       = "#affc41"; /* bar font color and tag color inactive */
static const char col_gray4[]       = "#ffffff"; /* current Tag Color */
static const char col_cyan[]        = "#000000"; /* middle bar color and border active window */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = {"","","","","",""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "TelegramDesktop",  NULL,       NULL,       1 << 3,       0,           -1 },	
	/*{ "firefox",  NULL,       NULL,       1 << 1,       0,           -1 },*/
};
/*
 * Power Things 
 *
 */

static const char *powermenu[] = {"/home/kf/.scripts/powermenu.sh", NULL};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "kitty", NULL }; /*  kitty, NULL */

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } }, /* open the dmenu to open applications */
	{ MODKEY,             		XK_Return, spawn,          {.v = termcmd } }, /* open the termianl kitty */
	{ MODKEY|ShiftMask,		XK_s,	   spawn,  	   {.v = powermenu} }, /* open the power menu to shutdown or sleep*/
	{ MODKEY,                       XK_b,      togglebar,      {0} }, /* hid the top bar that contain the clock and tabs */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },/* move between applications*/
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, /* move between applications */
	{ MODKEY,                       XK_f,      incnmaster,     {.i = +1 } }, /* change the view to horizontal view*/
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, /* change the view to vertical view*/
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },/* increase or decrease the size of the application in screen*/
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, /* increase or decrease the size of the application in screeen */
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} }, /* substitute the application with the other application  " make the right left and the lift right */
	{ MODKEY,                       XK_Tab,    view,           {0} }, /* change between tabs */
	{ MODKEY,	                XK_q,      killclient,     {0} }, /* kill the application */
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[0]} },/* change the layout */
	{ MODKEY,                       XK_i,      setlayout,      {.v = &layouts[1]} },/* change the layout */
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[2]} }, /* change the layout*/
	{ MODKEY,                       XK_space,  setlayout,      {0} },/* change between the layouts */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, 
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, /* don't use this this is bad just bad */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, /* same as above */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, /* change between screens*/
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } }, /* change between screens */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, /* move the application from it's screen to other screen */
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } }, /* same as above*/
	TAGKEYS(                        XK_1,                      0)/* move to tab number */
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(			XK_6,			   5)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} }, /* terminat the DWM */ /* used to restart the window manager*/
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


