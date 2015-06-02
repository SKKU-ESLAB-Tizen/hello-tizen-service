#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "common.h"
#include <dlog.h>
#include <glib.h>

#undef LOG_TAG
#define LOG_TAG "HELLO_TIZEN_SVC"

static GMainLoop* gMainLoop = NULL;
gboolean timeout_func_cb(gpointer data)
{
	if(gMainLoop)
	{
		ALOGD("Main loop will be terminated.");
		g_main_loop_quit((GMainLoop*)data);
	}
	return FALSE;
}

int main(int argc, char *argv[])
{
	int error, ret = 0;

	// Initialize a GTK main loop
	gMainLoop = g_main_loop_new(NULL, FALSE);
	ERR("HELLO Sevice started\n");
	printf("PHELLO Sevice started\n");

	// Add callbacks to main loop
	g_timeout_add(3, timeout_func_cb, gMainLoop); // Timeout callback: it will be called after 3000ms.

	// Start the main loop of service
	g_main_loop_run(gMainLoop);

	ERR("HELLO Serice is terminated successfully\n");
	printf("PHELLO Serice is terminated successfully\n");

	return ret;
}

//! End of a file
