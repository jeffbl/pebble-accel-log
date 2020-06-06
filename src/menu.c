#include <pebble.h>
#include "menu.h"
#include "prerun.h"
	
// Constants
#define NUMBER_OF_SECTIONS 1
#define NUMBER_OF_ITEMS 11

// Global variables
static Window *window;
static SimpleMenuLayer *menu_layer;
static SimpleMenuSection section_array[NUMBER_OF_SECTIONS];
static SimpleMenuItem users_array[NUMBER_OF_ITEMS];

// Loads the next screen whenever a menu item is selected
static void menu_select_callback(int index, void *context){
	prerun_init(index);
}

void menu_init(){
	window = window_create();
	
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);
	
	// Creating the menu entries
	users_array[0] = (SimpleMenuItem) {
		.title = "User A",
		.callback = menu_select_callback,
	};	
	users_array[1] = (SimpleMenuItem) {
		.title = "User B",
		.callback = menu_select_callback,
	};	
	users_array[2] = (SimpleMenuItem) {
		.title = "User C",
		.callback = menu_select_callback,
	};	
	users_array[3] = (SimpleMenuItem) {
		.title = "User D",
		.callback = menu_select_callback,
	};	
	users_array[4] = (SimpleMenuItem) {
		.title = "User E",
		.callback = menu_select_callback,
	};	
	users_array[5] = (SimpleMenuItem) {
		.title = "User F",
		.callback = menu_select_callback,
	};	
	users_array[6] = (SimpleMenuItem) {
		.title = "User G",
		.callback = menu_select_callback,
	};	
	users_array[7] = (SimpleMenuItem) {
		.title = "User H",
		.callback = menu_select_callback,
	};	
	users_array[8] = (SimpleMenuItem) {
		.title = "User I",
		.callback = menu_select_callback,
	};		
	users_array[9] = (SimpleMenuItem) {
		.title = "User J",
		.callback = menu_select_callback,
	};	
	users_array[10] = (SimpleMenuItem) {
		.title = "User K",
		.callback = menu_select_callback,
	};

	// Adding entries to the section
	section_array[0] = (SimpleMenuSection) {
		.num_items = NUMBER_OF_ITEMS,
		.items = users_array
	};
	
	// Adding the menu to the window
	menu_layer = simple_menu_layer_create(bounds, window, section_array, NUMBER_OF_SECTIONS, NULL);
	layer_remove_child_layers(window_get_root_layer(window));
	layer_add_child(window_layer, simple_menu_layer_get_layer(menu_layer));
	
	window_stack_push(window, true);
}

void menu_deinit(){
	prerun_deinit();
	layer_remove_from_parent(simple_menu_layer_get_layer(menu_layer));
	simple_menu_layer_destroy(menu_layer);
	window_destroy(window);
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Finished menu");
}
