(function() {
  window.JWP = window.JWP || {};
}).call(this);

(function() {
  JWP.Create = (function() {
    function Create() {
      JWP.player = this;
      jQuery(document).ready( function() {
        jwplayer('main-video').setup( JWP.player.settings() );
        jwplayer('main-video').onResize( JWP.player.resize );
      });
    }

    Create.prototype.jwData = function( name ) {
      var $jwplayerContainer = jQuery('#main-video-wrapper');
      return $jwplayerContainer.data( name );
    };

    Create.prototype.screenWidth = function() {
      return document.documentElement.clientWidth;
    };

    Create.prototype.listbarPosition = function() {
      this.position = ( this.screenWidth() >= 769 ) ? "right" : "bottom"
      return this.position;
    };

    Create.prototype.listbarSettings = function() {
      return {
        position:       this.listbarPosition(),
        layout:         "extended",
        size:           299
      }
    };

    Create.prototype.settings = function() {
      return {
        // Source
        image:          this.jwData( 'jwposterFrame' ),
        playlist:       this.jwData( 'jwplaylist'),

        // Display
        aspectratio:    "16:9",
        displaytitle:   false,
        height:         360,
        stretching:     "uniform",
        width:          "100%",
        // Playback
        autostart:      false,
        fallback:       false,
        primary:        "flash",
        repeat:         false,
        stagevideo:     false,
        // Controls
        controls:       true,
        listbar:        this.listbarSettings(),
        // Analytics
        analytics: {
          enabled:      false
        },
        ga: {
          idstring:     'title'
        },
        sitecatalyst: {
          mediaName: '  Teach Film Playlist',
          playerName:   'Teach Campaign Player'
        },
        // Sharing
        sharing: {
          link:         "http://www.takepart.com/teach/film"
        }
      }
    };

    Create.prototype.resize = function( data ) {
      var lastLayout = JWP.player.position;
      JWP.player.listbarPosition()
      if ( lastLayout != JWP.player.position )
        JWP.player.constructor();
    };

    return Create;

  })();
}).call(this);

new JWP.Create();
