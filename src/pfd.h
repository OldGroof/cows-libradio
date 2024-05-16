#ifndef PFD_H
#define PFD_H

#include "G1000.h"

struct pfd_nvram_s {
	bool baro_hpa;
	bool second_alt;
	int inset_frmt;
	int hsi_frmt;
	int cdi;
	int brg1;
	int brg2;
	float nav1crs;
	float nav2crs;
	float com1_vol;
	float com2_vol;
	float nav1_vol;
	float nav2_vol;
	int wind_frmt;
	bool show_dme;
	int dme_slave_mode;

	bool ref_glide;
	bool ref_vr;
	int Vr;
	bool ref_vx;
	bool ref_vy;
	bool ref_vle;
	bool ref_vlo;

	bool map_wxlegend;
	map_up_t map_up;
	uint16_t map_range;
	uint8_t map_detail;
	bool map_show_traffic;
	bool map_nexrad;
	bool map_xm_light;
	bool map_wxr;
	map_topo_t map_topo;
	map_awy_t map_awy;
	bool map_nrth_up_above;
	int map_nth_up_rng;
	bool map_trk_v;
	int map_trk_v_option;
	bool map_sel_alt_arc;
	bool map_wind_v;
	bool map_fuel_rng;
	int map_tfc_rng;
	bool map_tfc_lbl;
	int map_tfc_lbl_rng;

	bool map_lrg_arp;
	int map_lrg_arp_rng;
	bool map_med_arp;
	int map_med_arp_rng;
	bool map_sml_arp;
	int map_sml_arp_rng;
	bool map_miss_app;
	bool map_shw_int;
	int map_int_rng;
	bool map_shw_ndb;
	int map_ndb_rng;
	bool map_shw_vor;
	int map_vor_rng;
	bool map_vor_rose;
	bool map_shw_vrp;
	int map_vrp_rng;
	bool map_shw_vnv_cnst;
	int map_vnv_cnst_option;

	bool map_class_b;
	int map_cl_b_rng;
	bool map_class_c;
	int map_cl_c_rng;
	bool map_class_a;
	int map_cl_a_rng;
	bool map_rstrct;
	int map_rstrict_rng;

	auto operator<=>(const pfd_nvram_s&) const = default;
};
struct PFD_s {
	/* PFD Global Variables */
	bool on = false;
	XPLMDataRef failDRef = NULL;
	bool fail = true;

	bool reversion = false;
	float bootTimer = 0;
	bool inBoot = true;
	bool nvram_loaded = false;
	bool bootComplete = false;
	float blinker;
	float input_blinker;
	float hdg_timer;
	float crs_timer;
	float nav1_anim;
	float nav1_vol_timer;
	float nav2_anim;
	float nav2_vol_timer;
	float com1_anim;
	float com1_vol_timer;
	float com2_anim;
	float com2_vol_timer;

	XPLMDataRef brt_dref = NULL;
	float brt_val = -1;

	int man_bright = 0;
	double brightness = 1;
	XPLMDataRef light_r = NULL;
	XPLMDataRef light_g = NULL;
	XPLMDataRef light_b = NULL;
	float light_lvl;

	XPLMDataRef alt_alerterDRef;
	int alt_alerter;
	int alt_alerter_old;
	float aa_blinker;
	float aa_timer;

	float gps_loi_timer;

	double wind_dir = NAN;
	double wind_spd = NAN;
	double wind_h = NAN; // positive is from the front
	double wind_x = NAN; // positive is from the right

	cas_param_s cas;
	XPLMDataRef mstr_warn = NULL;
	XPLMDataRef plugin_mstr_warn = NULL;
	XPLMDataRef mstr_caut = NULL;
	XPLMDataRef plugin_mstr_caut = NULL;
	XPLMCommandRef accept_caut = NULL;
	XPLMCommandRef accept_warn = NULL;

	// timer
	timer_params_s timer;

	/* MINIMUMS */
	baro_type_t baro_setting;             /* No rad-alt yet */
	XPLMDataRef baro_alt_bugDRef = NULL;  /* set this to baro_alt */
	int baro_alt_set = -3000;             /* What is set on menu */
	int baro_alt = -3000;                 /* What is displayed (including temp correction) */
	int baro_temp = 0;                    /* Temperature setting for temp correction */

	bool show_menu;
	float menu_scale;

	bool show_page_menu;
	float page_menu_scale;
	int page_menu_scroll;

	bool show_fpl;
	float fpl_scale;
	int fpl_items;
	int fpl_scroll;

	bool show_wpt_search = false;
	float wpt_search_scale = 0;
	std::string wpt_search_name;
	std::vector<wpt_search_s>wpt_search_results;

	bool show_dup_wpts = false;
	float dup_wpts_scale = 0;
	int dup_wpts_scroll = 0;

	bool show_fpl_rwys = false;
	float fpl_rwys_scale = 0;
	airport_s* fpl_rwys_airport = nullptr;
	int fpl_rwys_sel = 0;
	segment_t* fpl_rwys_dest_seg = nullptr;

	bool show_fpl_remove_item = false;
	float fpl_remove_item_scale = 0;
	segment_t* fpl_remove_item_seg = nullptr;
	leg_t* fpl_remove_item_leg = nullptr;
	bool fpl_remove_item_is_title = false;
	bool fpl_remove_item_is_airport = false;

	bool show_fpl_void_del;
	float void_del_scale = 0;

	bool show_del_arc = false;
	float del_arc_scale = 0;

	bool show_prc;
	float proc_scale;

	bool sel_dep;
	float sel_dep_scale;

	bool sel_arr;
	float sel_arr_scale;

	bool sel_apr;
	float sel_apr_scale;
	baro_type_t apr_baro;
	int apr_baro_alt = -3000;
	int apr_baro_alt_temp = -3000;
	int apr_baro_temp = 15;

	bool show_apr_gps_monitor = false;
	float apr_gps_monitor_scale = 0.0;
	bool apr_activate = false;

	int selected_proc_rwyt = 0;
	int selected_procedure = 0;
	int selected_proc_enrt = 0;
	std::vector<leg_t> procedure;

	bool show_dct;
	float dct_scale;
	std::string dct_search_name;
	std::vector<wpt_search_s>dct_search_result;
	int direct_to_sel_course = 360;
	leg_t* direct_to_leg = nullptr;

	bool show_dmeadf;
	float dmeadf_scale;

	bool show_tmr;
	float tmr_scale;
	int tmr_scroll;

	bool show_nrst;
	float nrst_scale;

	bool show_alerts;
	float alerts_scale;

	map_params_t map;
	uint16_t sel_map_range = 25;
	bool map_wxlegend;

	mutex_t map_wpt_list_mutex;
	mutex_t map_arpt_list_mutex;
	mutex_t map_back_list_mutex;
	mutex_t map_airspace_list_mutex;
	worker_t map_worker;

	mutex_t map_terrain_mute;
	geo_pos2_t prev_terr_cent;
	float prev_terr_scale = 0;

	mutex_t map_background_mute;
	worker_t map_background_worker;

	mutex_t map_airspace_mute;
	worker_t map_airspace_worker;

	/* PFD Variables */
	int cursor;
	int prev_cursor;

	int inputs;
	bool in_input;
	double show_input_scale = 0.0;
	input_s current_input;

	bool baro_std;
	float non_std_baro;
	bool baro_hpa;           /* NVRAM */
	bool show_secondary_alt; /* NVRAM */
	int inset_frmt;			 /* NVRAM (0-Off, 1-Inset Map, 2-Inset Trfc) */
	int hsi_frmt;            /* NVRAM (0-HSI, 1-Map HSI, 2-Trfc HSI) */
	int cdi;                 /* NVRAM */
	XPLMDataRef cdiDRef = NULL;
	float nav1crs;           /* NVRAM */
	float nav2crs;           /* NVRAM */
	XPLMDataRef nav1crsDRef = NULL;
	XPLMDataRef nav2crsDRef = NULL;
	int com_select = 1;
	int nav_select = 1;
	int brg1;                /* NVRAM (off,nav1,nav2,gps,adf) */
	int brg2;                /* NVRAM (off,nav1,nav2,gps,adf) */
	int wind_frmt;           /* NVRAM (0-off, 1-components, 2-combined, 3-H/X) */
	bool show_dme;           /* NVRAM */

	float alt_translate, whole, fract;
	int intWhole;

	/* References */
	bool ref_glide = false;  /* NVRAM */
	bool ref_vr = false;     /* NVRAM */
	bool ref_vx = true;      /* NVRAM */
	bool ref_vy = true;      /* NVRAM */
	bool ref_vle = true;     /* NVRAM */
	bool ref_vlo = true;     /* NVRAM */

	XPLMCommandRef pop_up = NULL;
	
	/* Button Commands */
	XPLMCommandRef nav_vol_up = NULL;
	XPLMCommandRef nav_vol_down = NULL;
	XPLMCommandRef nav_ff = NULL;
	XPLMCommandRef nav_outer_up = NULL;
	XPLMCommandRef nav_outer_down = NULL;
	XPLMCommandRef nav_inner_up = NULL;
	XPLMCommandRef nav_inner_down = NULL;
	XPLMCommandRef nav_push = NULL;
	XPLMCommandRef hdg_up = NULL;
	XPLMCommandRef hdg_down = NULL;
	XPLMCommandRef hdg_sync = NULL;

	XPLMCommandRef sim_hdg_up = NULL;
	XPLMCommandRef sim_hdg_down = NULL;
	XPLMCommandRef sim_hdg_sync = NULL;

	XPLMCommandRef ap = NULL;
	XPLMCommandRef yd = NULL;
	XPLMCommandRef fd = NULL;
	XPLMCommandRef hdg = NULL;
	XPLMCommandRef nav = NULL;
	XPLMCommandRef apr = NULL;
	XPLMCommandRef alt = NULL;
	XPLMCommandRef vnv = NULL;
	XPLMCommandRef vs = NULL;
	XPLMCommandRef nu = NULL;
	XPLMCommandRef flc = NULL;
	XPLMCommandRef nd = NULL;

	XPLMCommandRef sim_vvi_up = NULL;
	XPLMCommandRef sim_vvi_down = NULL;

	XPLMCommandRef alt_outer_up = NULL;
	XPLMCommandRef alt_outer_down = NULL;
	XPLMCommandRef alt_inner_up = NULL;
	XPLMCommandRef alt_inner_down = NULL;

	XPLMCommandRef sim_alt_up = NULL;
	XPLMCommandRef sim_alt_down = NULL;

	XPLMCommandRef com_vol_up = NULL;
	XPLMCommandRef com_vol_down = NULL;
	XPLMCommandRef com_ff = NULL;
	XPLMCommandRef com_outer_up = NULL;
	XPLMCommandRef com_outer_down = NULL;
	XPLMCommandRef com_inner_up = NULL;
	XPLMCommandRef com_inner_down = NULL;
	XPLMCommandRef com_push = NULL;
	XPLMCommandRef baro_up = NULL;
	XPLMCommandRef baro_down = NULL;
	XPLMCommandRef crs_up = NULL;
	XPLMCommandRef crs_down = NULL;
	XPLMCommandRef crs_sync = NULL;

	XPLMCommandRef rng_up = NULL;
	XPLMCommandRef rng_dn = NULL;
	// cursor

	XPLMCommandRef softkey1 = NULL;
	XPLMCommandRef softkey2 = NULL;
	XPLMCommandRef softkey3 = NULL;
	XPLMCommandRef softkey4 = NULL;
	XPLMCommandRef softkey5 = NULL;
	XPLMCommandRef softkey6 = NULL;
	XPLMCommandRef softkey7 = NULL;
	XPLMCommandRef softkey8 = NULL;
	XPLMCommandRef softkey9 = NULL;
	XPLMCommandRef softkey10 = NULL;
	XPLMCommandRef softkey11 = NULL;
	XPLMCommandRef softkey12 = NULL;
	XPLMCommandRef fms_inner_down = NULL;
	XPLMCommandRef fms_inner_up = NULL;
	XPLMCommandRef fms_outer_down = NULL;
	XPLMCommandRef fms_outer_up = NULL;
	XPLMCommandRef fms_cursor = NULL;
	fms_knob_s fms_knob;
	XPLMCommandRef dct = NULL;
	XPLMCommandRef menu = NULL;
	XPLMCommandRef fpl = NULL;
	XPLMCommandRef proc = NULL;
	XPLMCommandRef clr = NULL;
	void (*but_clr)() = nullptr;
	XPLMCommandRef ent = NULL;
	void (*but_ent)() = nullptr;

	/* Lower Menu Params */
	lower_menu_s lower_menu;
	float lower_timer;
	void (*lwr_return_func)() = nullptr;

	/* PFD Renderer */
	XPLMDataRef viewportDRef = NULL;
	mt_cairo_render_t* pfd_render = NULL;
#if XPLM400
	XPLMAvionicsID AvionicsID;
	XPLMAvionicsID cust_avionics_id;
#else
	XPLMWindowID window;
#endif
};

void pfdImagesInit();
void pfd_datarefs_init();
void pfd_commands_init();

void pfdImagesFini();
void pfd_datarefs_fini();
void pfd_commands_fini();

void pfdActive(cairo_t* cr);

void pfdDisplayRender(cairo_t*, unsigned, unsigned, void*);
int pfdDrawLoop(XPLMDrawingPhase, int, void*);

#if XPLM400
int pfdAvionicsDrawLoop(XPLMDeviceID inDeviceID, int inIsBefore, void* inRefcon);
int pfdCustAvionicsDrawLoop(XPLMDeviceID inDeviceID, int inIsBefore, void* inRefcon);
#else
void pfdWindowDrawLoop(XPLMWindowID inWindowID, void* inRefcon);
#endif

bool_t pfdMapBackgroundWorkerThread(void* unused);
bool_t pfdMapAirspaceWorkerThread(void* unused);
bool_t pfd_map_worker_thread(void* unused);

float pfd_render_terr(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void* inRefcon);

float pfd_flight_loop(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void* inRefcon);
float pfd_nvram_floop(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void* inRefcon);

float GetPFDBrt(void* inRefcon);
void SetPFDBrt(void* inRefcon, float inValue);

void pfd_read_nvram();
void pfd_write_nvram();

#endif