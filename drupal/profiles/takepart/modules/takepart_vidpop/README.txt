Deployment:

This feature adds some new files to the site:

sites/modules/contrib/colorbox
profiles/modules/takepart/modules/takepart_vidpop

1) add field to video content type:
field_video_display_mode

label:
Embedded video mode

help:
Display video as a modal popup, embedded within the page, or as embedded on the permalinked page and modal everywhere else it is used.

type: list (integer; radios)
1|embedded
2|modal popup
3|contextual (embedded on permalink page, modal elsewhere)

move to after field_video_embedded
edit, set default to modal popup

2) Create image style tp_embed_video_thumb
		add effect: scale and crop to 420x315


3) enable module TakePart Video Popup Support


4) enable module colorbox

		in colorbox config, click "enable colorbox inline"

================================================

To test:

1) edit a video clip; I used node 23967:
http://alpha.takepart.com/article/2012/06/01/humane-society-legislative-fund-iowa-race-ag-gag

under media, set embedded video mode to modal popup

2) edit an article; I used node 24791
http://alpha.takepart.com/article/2012/06/01/humane-society-legislative-fund-iowa-race-ag-gag

In the body field, click on the embed icon, add your video clip (I typed in "Ice Cream" to find it)

save the node

View the node, the popup will be displayed.
