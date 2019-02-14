
#include <windows.h>
#include <vlc/vlc.h>

int main()
{
	libvlc_instance_t *vlc_instance;
	libvlc_media_player_t *media_player;
	libvlc_media_t *media;

	int wait_time = 1000 * 20;

	vlc_instance = libvlc_new(0, NULL);
	//media = libvlc_media_new_location(vlc_instance, "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_175k.mov");
	media = libvlc_media_new_path(vlc_instance, "media\\BigBuckBunny_320x180_Trim.mp4");
	media_player = libvlc_media_player_new_from_media(media);

	libvlc_media_release(media);

	libvlc_media_player_play(media_player);
	
	Sleep(wait_time);

	libvlc_media_player_stop(media_player);

	libvlc_media_player_release(media_player);

	libvlc_release(vlc_instance);

	return 0;

}