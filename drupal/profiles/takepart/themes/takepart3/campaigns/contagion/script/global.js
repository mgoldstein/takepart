(function(window, $, undefined) {


//Vars
var winWidth = ($(window).width()) - 20;	
var designWidth = 908;
var panelWidthPercent = '';
var timelineOpen = false;
var healthMapUrl = 'http://healthmap.org/participantmedia/';
var videoOverlay = 'http://www.youtube.com/embed/WZIGFPCSoII';
var RssCDCFeed = 'http://www2c.cdc.gov/podcasts/createrss.asp?t=r&c=233';

//Solves for percent
function percentWidth() {				
	a = designWidth; //width of scrolling panels
	b = winWidth; //width of browser window
	c = [(a/b) * 100] + '';									
	d = c.replace('.', '');
	e = '.' + (d);
	return e; //percent width
}						
panelWidthPercent = percentWidth();

//Load Twitter iFrame
var loadTwitterURL = (function() {
	$('#twitterFrame').attr('src', '/sites/default/files/contagion/twitterFeed.html');
});

//Delay for page resize
var delay = (function(){
  var timer = 0;
  return function(callback, ms){
    clearTimeout (timer);
    timer = setTimeout(callback, ms);
  };
})();

var rssScroller = (function() {
	$("#CDCFeed .rssBody").scrollable({ 
		items: "ul",
		next: ".nextPartners",
		prev: ".prevPartners",
		vertical: true, 
		mousewheel: true,
		circular: true,		
		keyboard: false	
	}).autoscroll({ interval: 4000 });
});
setTimeout(rssScroller, 4000);

var rssScrollerPandemic = (function() {
	$("#CDCFeedPandemic .rssBody").scrollable({ 
		items: "ul",
		next: ".nextPandemic",
		prev: ".prevPandemic",
		vertical: true, 
		mousewheel: true,
		circular: true,		
		keyboard: false	
	}).autoscroll({ interval: 4000 });
});
setTimeout(rssScrollerPandemic, 4000);

var rssScrollerActivities = (function() {
	$("#CDCFeedActivities .rssBody").scrollable({ 
		items: "ul",
		next: ".nextActivities",
		prev: ".prevActivities",
		vertical: true, 
		mousewheel: true,
		circular: true,		
		keyboard: false	
	}).autoscroll({ interval: 4000 });
});
setTimeout(rssScrollerActivities, 4000);

var rssScrollerExplore = (function() {
	$("#CDCFeedExplore .rssBody").scrollable({ 
		items: "ul",
		next: ".nextExplore",
		prev: ".prevExplore",
		vertical: true, 
		mousewheel: true,
		circular: true,		
		keyboard: false	
	}).autoscroll({ interval: 4000 });
});
setTimeout(rssScrollerExplore, 4000);
	
	
//SnapApp
var snapAppInit = (function(){
	var s = document.createElement('script');
    s.type = 'text/javascript';
    s.async = true;
    var src = document.location.protocol + '//';
    src += (document.location.protocol == 'http:') ?
      'cdn.snapapp.com' : 'scdn.snapapp.com';
    src += '/widget/widget.js';
    s.src = src;
    s.id = 'eeload';
    document.getElementsByTagName('head')[0].appendChild(s);
});

var snapAppInitAlt = (function(){
	var s = document.createElement('script');
    s.type = 'text/javascript';
    s.async = true;
    var src = document.location.protocol + '//';
    src += (document.location.protocol == 'http:') ?
      'cdn.snapapp.com' : 'scdn.snapapp.com';
    src += '/widget/widget.js';
    s.src = src;
    s.id = 'eeload';
    document.getElementsByTagName('head')[0].appendChild(s);
});

//Moving Box Init
var MBInit = (function() {
	$('.section').show();
	
	//Step 01::: Build MB
	$('#slider-one').movingBoxes({
		startPanel   : 3,      		// start with this panel
		width        : winWidth,    // overall width of Moving Boxes (not including navigation arrows)
		panelWidth   : panelWidthPercent,       // current panel width adjusted to overall width
		reducedSize  : 1,
		hashTags     : true,
		fixedHeight  : true,
		wrap         : false,   	// if true, the panel will "wrap" (it really rewinds/fast forwards) at the ends
		buildNav     : false,   	// if true, navigation links will be added
		initialized  : function(e, slider, tar){								
											
			//Calculate height
			var panelHeight = $(document).height();
			$('.mb-scroll').css('height', panelHeight);
			$('.movingBoxes').css('height', panelHeight);
																																							
			//Sets the header navigation link state and more
			switch(tar) {
				case 1:
					$('#panel01').addClass('panelCurrent').siblings('div').addClass('panelBlur');
					$('#ActivitiesPanel').addClass('current');						
					$('.mb-left').hide();
					break;
				case 2:
					$('#panel02').addClass('panelCurrent').siblings('div').addClass('panelBlur');	
					$('#PandemicPanel').addClass('current');												
					$('#healthmap').attr('src', healthMapUrl);
					break;
				case 3:
					$('#panel03').addClass('panelCurrent').siblings('div').addClass('panelBlur');						
					$('#EpicenterPanel').addClass('current');						
					setTimeout(loadTwitterURL, 1000);
					break;
				case 4:
					$('#panel04').addClass('panelCurrent').siblings('div').addClass('panelBlur');
					$('#ExplorePanel').addClass('current');						
					break;
				case 5:						
					$('#panel05').addClass('panelCurrent').siblings('div').addClass('panelBlur');
					$('#PartnersPanel').addClass('current');
					$('.mb-right').hide();
					break;
			};
			
			//Scrolls site to top
			$('html, body').animate({ scrollTop: 0 }, 'slow');
			
			//TopNav click MB navigation
			var mb = $('#slider-one').getMovingBoxes();											
			$('#ActivitiesPanel').click(function(){
				mb.currentPanel(1);
			});
			$('#PandemicPanel').click(function(){
				mb.currentPanel(2);
			});
			$('#EpicenterPanel').click(function(){
				mb.currentPanel(3);
			});
			$('#ExplorePanel').click(function(){
				mb.currentPanel(4);
			});
			$('#PartnersPanel').click(function(){
				mb.currentPanel(5);
			});		
			$('#virusHunters').click(function(){
				mb.currentPanel(4);
			});
											
			//SnapApp Init
			setTimeout(snapAppInit, 1000);
			setTimeout(snapAppInitAlt, 1000);
			
			//Reload
			$(window).resize(function() {
				delay(function(){					
					window.location.reload()													
				}, 1000);
			});
			
			//Append DIV to L/R Nav Arrows
			$('a.mb-scrollButtons').append('<span></span>');
		}
	});	
});
	
$(function() {

//Target prev or next selected MB panel
$('#slider-one').bind('completed.movingBoxes',function(e, slider, tar){
	$('.mb-panel').removeClass('panelCurrent').addClass('panelBlur');
	$(this).children('.mb-panel:nth-child(' + tar + ')').addClass('panelCurrent').removeClass('panelBlur');
	$('.mb-scrollButtons').show();
	
	//Sets the header navigation link state and more
	switch(tar) {
		case 1:
			$('.header a').removeClass('current');
			$('#ActivitiesPanel').addClass('current');
			$('.mb-left').hide();
			break;
		case 2:
			$('.header a').removeClass('current');
			$('#PandemicPanel').addClass('current');
			
			var currentHMUrl = $('#healthmap').attr('src');						
			if (currentHMUrl == healthMapUrl){
				break;
			}
			else {
				$('#healthmap').attr('src', healthMapUrl);							
			}		
			break;
		case 3:
			$('.header a').removeClass('current');
			$('#EpicenterPanel').addClass('current');
			
			var currentTwitterUrl = $('#twitterFrame').attr('src');						
			if (currentTwitterUrl == '/sites/default/files/contagion/twitterFeed.html'){
				break;
			}
			else {
				setTimeout(loadTwitterURL, 1000);					
			}							
			break;
		case 4:
			$('.header a').removeClass('current');
			$('#ExplorePanel').addClass('current');
			break;
		case 5:
			$('.header a').removeClass('current');
			$('#PartnersPanel').addClass('current');
			$('.mb-right').hide();
			break;			
	}
	
	//Hide footer Timeline on panel slide
	$('#timeline').animate({
		'bottom': '-185px'
	}, 'swing');
	timelineOpen = false;
	
	//Scrolls site to top
	var goToTop = function() {
		$('html, body').animate({ scrollTop: 0 }, 'slow');
	}
	setTimeout(goToTop, 800);				
});			

//RSS Feed of CDC
$('#CDCFeed').rssfeed(RssCDCFeed, { 
	limit: 10,
	header: false,
	date: false,
	content: false,
	snippet: false,
	linktarget: '_blank'
});
$('#CDCFeedPandemic').rssfeed(RssCDCFeed, { 
	limit: 10,
	header: false,
	date: false,
	content: false,
	snippet: false,
	linktarget: '_blank'
});
$('#CDCFeedActivities').rssfeed(RssCDCFeed, { 
	limit: 10,
	header: false,
	date: false,
	content: false,
	snippet: false,
	linktarget: '_blank'
});
$('#CDCFeedExplore').rssfeed(RssCDCFeed, { 
	limit: 10,
	header: false,
	date: false,
	content: false,
	snippet: false,
	linktarget: '_blank'
});
	
//Overlay
$('a.overlayTrigger').overlay({
	mask: '#000',
	opacity: .8
});
 

//Overlay Video
$('.overlayTriggerHome').click(function(){
	$('#overlayVideoContent').attr('src', videoOverlay);
});
	

//Btn functions
$('#q01True').click(function() {
	$('#q01AnswerTrue').show();	
});

$('#q01False').click(function() {
	$('#q01AnswerFalse').show();	
});

$('.btnClose').click(function() {
	$('#q01AnswerTrue').hide();
	$('#q01AnswerFalse').hide();
});

$('.info_towers').bind('mouseenter', function() {
	$(this).siblings('.tower_preview').show();
})
$('.tower_preview').bind('mouseleave', function() {
	$(this).hide();
})

//Scrollable Footer Timeline Init
$('#chained').scrollable({
	keyboard: false
}).navigator();			
var naviWidth = $('.naviContainer').width();
var naviHalf = naviWidth / 2;
var naviMarginLeft = 450 - naviHalf;
$('.naviContainer').css('margin-left', naviMarginLeft);

$('.flag').click(function(){
	$(this).css('z-index', '10');
	$(this).children('.flagContent').show();
}).mouseleave(function(){
	$(this).css('z-index', '1');
	$(this).children('.flagContent').hide();
});

$('.flagContent').mouseleave(function(){
	$(this).parent('a').css('z-index', '1');
	$(this).hide();
});


//WinOS detection
if (navigator.appVersion.indexOf("Win")!=-1) {
	$('#join-login-top span.fb').css('bottom', '-2px');
	$('#user-nav li').css('marginTop', '4px');
}


//iPad detection for timeline alt functionality
var isIPad = navigator.userAgent.match(/iPad/i) != null;
if(isIPad) {
	$('body').css('backgroundColor', '#222222');
	$('.footer').css('position', 'relative');
	$('.footer').css('bottom', '0px');
	$('.footer').css('height', '50px');
	$('.footerContainer').css('margin', '0px');
	$('.footerContainer').css('paddingTop', '20px');
	$('#timeline').css('position', 'relative');
	$('#timeline').css('bottom', '0');
	$('#timeline').css('backgroundColor', '#222222');
	$('a.timelineClose').hide();
	$('a.timelineOpen').html('Learn how pandemics have changed the world');
}
else {
	//Footer Timeline Functions	
	//Activate timeline
	$('.timelineOpen').click(function(){
		if(timelineOpen == false) {
			//Open timeline
			$('#timeline').animate({
				'bottom': '55px'
			}, 'swing');	
			timelineOpen = true;								
		}
		else {
			//Close timeline
			$('#timeline').animate({
				'bottom': '-185px'
			}, 'swing');
			timelineOpen = false;			
		}		
	});
		
	//Close timeline
	$('.timelineClose').click(function(){
		$('#timeline').animate({
			'bottom': '-185px'
		}, 'swing');
		timelineOpen = false;
	});	
}

//Tabs Init
$('ul.tabs').tabs('div.panes > div', { history: false });

});

//Activate Moving Boxes			
$(document).ready(function(){
	setTimeout(MBInit, 1000);
	
	$('.dhtml-menu').mouseenter(function(){
		$(this).children('.menu').show();
	}).mouseleave(function(){
		$(this).children('.menu').hide();
	});		
});

})(window, jQuery);