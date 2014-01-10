var tpanalytics = tpanalytics || {};
tpanalytics['media'] = tpanalytics['media'] || {};

tpanalytics['media'].jwPlayer = {
    track: function () {
        if ((typeof (jwplayer) !== 'undefined') && jwplayer) {
            //Plays:
            jwplayer().onPlay(function (event) {
                console.log('play');
                var mediaOffset = jwplayer().getPosition(); //seconds
                var pl = jwplayer().getPlaylist();
                var mediaName = pl[0]['title'];
                if(tpanalytics.media.jwPlayer.history['lastaction'] == 'complete') {
                    var mediaLength = jwplayer().getDuration(); //seconds
                    var mediaPlayerName = 'JW Player ' + jwplayer['version'];
                    s.Media.open(mediaName,mediaLength,mediaPlayerName);
                    tpanalytics.media.jwPlayer.history['lastaction'] = 'open';
                }
                if(tpanalytics.media.jwPlayer.history['lastaction'] == 'open') {
                    s.Media.play(mediaName, mediaOffset);
                    tpanalytics.media.jwPlayer.history['lastaction'] = 'play';
                }
            });
            //Opens:
            jwplayer().onReady(function (event) {
                console.log('open');var mediaPlayerName = 'JW Player ' + jwplayer['version'];
                var mediaLength = jwplayer().getDuration(); //seconds
                var pl = jwplayer().getPlaylist();
                var mediaName = pl[0]['title'];
                s.Media.open(mediaName,mediaLength,mediaPlayerName);
                tpanalytics.media.jwPlayer.history['lastaction'] = 'open';
            });
            //Stops:
            jwplayer().onPause(function (event) {
                console.log('stop');
                var mediaOffset = jwplayer().getPosition(); //seconds
                var pl = jwplayer().getPlaylist();
                var mediaName = pl[0]['title'];
                s.Media.stop(mediaName, mediaOffset);
                tpanalytics.media.jwPlayer.history['lastaction'] = 'stop';
            });
            //Completes:
            jwplayer().onComplete(function () {
                console.log('complete');
                var pl = jwplayer().getPlaylist();
                var mediaName = pl[0]['title'];
                s.Media.close(mediaName);
                tpanalytics.media.jwPlayer.history['lastaction'] = 'complete';
            });
        }
    },
    history: {},
    onload: function () {
       if (typeof(jwplayer) !== 'undefined') {
          tpanalytics.media.jwPlayer.track();
       } else {
          setTimeout("tpanalytics.media.jwPlayer.onload();",1000);
       }
    }
};

tpanalytics.media.jwPlayer.onload();