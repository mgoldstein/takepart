(function() {
  window.JWP = window.JWP || {};
}).call(this);

(function() {
  JWP.Create = (function() {
    function Create() {
      JWP.player = this;
      jQuery(document).ready( function() {
        jwplayer('teach-film-player').setup( JWP.player.settings() );
      });
    }

    Create.prototype.jwData = function( name ) {
      var $jwplayerContainer = jQuery('#teach-film-player-wrapper');
      return $jwplayerContainer.data( name );
    };

    Create.prototype.screenWidth = function() {
      return document.documentElement.clientWidth;
    };

    Create.prototype.listbarPosition = function() {
      return ( this.screenWidth() >= 769 ) ? "right" : "bottom"
    };

    Create.prototype.listbarSettings = function() {
      return {
        position: this.listbarPosition(),
        layout:   "extended",
        size:     299
      }
    };

    Create.prototype.settings = function() {
      return {
        // Source
        image: this.jwData( 'jwposterFrame' ),
        playlist: this.jwData( 'jwplaylist'),
        // Display
        aspectratio: "16:9",
        displaytitle: false,
        height: 360,
        stretching: "uniform",
        width: "100%",
        // Playback
        autostart: false,
        fallback: false,
        primary: "flash",
        repeat: false,
        stagevideo: false,
        // Controls
        controls: true,
        listbar: this.listbarSettings(),
        // Analytics
        analytics: {
          enabled: false
        },
        ga: {
          idstring: 'title'
        },
        sitecatalyst: {
          mediaName: 'Teach Film Playlist',
          playerName: 'Teach Campaign Player'
        },
        // Sharing
        sharing: {
          link: "http://www.takepart.com/teach/film"
        }
      }
    };

    return Create;

  })();
}).call(this);

new JWP.Create();