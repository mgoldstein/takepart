(function()
{
	function forceHtmlMode( evt ) { evt.data.mode = 'html'; }

	CKEDITOR.plugins.add( 'pastefromgoogle',
	{
		init : function( editor )
		{

			// Flag indicate this command is actually been asked instead of a generic
			// pasting.
			var forceFromGoogle = 0;
			var resetFromGoogle = function( evt )
				{
					evt && evt.removeListener();
					editor.removeListener( 'beforePaste', forceHtmlMode );
					forceFromGoogle && setTimeout( function() { forceFromGoogle = 0; }, 0 );
				};

			// Features bring by this command beside the normal process:
			// 1. No more bothering of user about the clean-up.
			// 2. Perform the clean-up even if content is not from MS-Google.
			// (e.g. from a MS-Google similar application.)
			editor.addCommand( 'pastefromgoogle',
			{
				canUndo : false,
				exec : function()
				{
					// Ensure the received data format is HTML and apply content filtering. (#6718)
					forceFromGoogle = 1;
					editor.on( 'beforePaste', forceHtmlMode );

					if ( editor.execCommand( 'paste', 'html' ) === false )
					{
						editor.on( 'dialogShow', function ( evt )
						{
							evt.removeListener();
							evt.data.on( 'cancel', resetFromGoogle );
						});

						editor.on( 'dialogHide', function( evt )
						{
							evt.data.removeListener( 'cancel', resetFromGoogle );
						} );
					}

					editor.on( 'afterPaste', resetFromGoogle );
				}
			});

			// Register the toolbar button.
			editor.ui.addButton( 'pastefromgoogle_button',
				{
					label : 'Paste from Google',
					command : 'pastefromgoogle',
					icon : this.path + 'icons/pastefromgoogle.png'
				});

			editor.on( 'pasteState', function( evt )
				{
					editor.getCommand( 'pastefromgoogle' ).setState( evt.data );
				});

			editor.on( 'paste', function( evt )
			{
				var data = evt.data,
					googleHtml;

				// Google Doc format sniffing.
				if ( ( googleHtml = data[ 'html' ] )
					 && ( forceFromGoogle || ( /((strong|b|span) id="docs-internal-guid(.*))/ ).test( googleHtml ) ) )
				{
					result = googleHtml.replace(/<(strong|b|span) id="docs-internal-guid(.*?);">(.*)/gi, "$3");

					// strip out all tags except basic formatting
					result = result.replace(/<(font|span) (.*?)>/gi, "");
					//Strip all style
					result = result.replace(/style="(.*?)"/gi, "");

					data[ 'html' ] = result;
				}
			}, this );
		},

		requires : [ 'clipboard' ]
	});
})();
