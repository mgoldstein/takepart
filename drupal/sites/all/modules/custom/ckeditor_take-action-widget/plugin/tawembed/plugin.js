/*
* @file A simple textarea dialog to allow snippets of HTML to be inserted.
*/
( function() {
  CKEDITOR.plugins.add( 'TAWEmbed',
  {
    requires: [ 'iframedialog' ],
    init: function( editor )
    {
      var me = this;
      CKEDITOR.dialog.add( 'TAWEmbedDialog', function ( editor )
      {
        return {
          title : 'Embed Take Action Widget',
          minWidth : 230,
          minHeight : 100,
          contents :
          [
            {
              id : 'tawTab',
              label : 'Embed TAW code',
              title : 'Embed TAW code',
              elements :
              [
  		{
                  id : 'targeturl',
                  type : 'text',
                  label : 'Target URL',
                },
                {
                  id : 'expand',
                  type : 'checkbox',
                  label : 'Expanded?',
                }
              ]
            }
          ],
          onOk : function()
          {
            var expand = this.getValueOf( 'tawTab', 'expand' );
	    var targeturlval = this.getValueOf( 'tawTab', 'targeturl' );
	    var width = "100%";
	    var dfstyle = "";
	    var placeholdertext = 'Take Action Widget';
	    var targeturl = "";
	    if(expand) { 
		dfstyle = ' data-form-style="expanded"';
	    }
 	    if(targeturlval) {
	        targeturl = ' data-article-url="' + targeturlval + '"';
	    }
            final_html = 'TAWEmbedInsertData|---' + escape('<div class="takepart-take-action-widget" style="width: '+width+';"'+dfstyle+targeturl+'></div>') + '---|TAWEmbedInsertData';
            editor.insertHtml(final_html);
            updated_editor_data = editor.getData();
            clean_editor_data = updated_editor_data.replace(final_html,'<div class="takepart-take-action-widget" style="width: '+width+';"'+dfstyle+targeturl+'></div>');
            editor.setData(clean_editor_data);
	    if(TP) {
 	        if(typeof TP.WidgetFrame == 'function') {
	    		TP.WidgetFrame;
                }
	    }
	   
	 var iframeWin=jQuery('.cke_contents iframe')[0].contentWindow;

	 var script = iframeWin.document.createElement("link");

        //@todo: fix this:
/*
	 script.type = "text/css";
	 script.rel = "stylesheet";
	 script.href="/sites/all/modules/custom/ckeditor_take-action-widget/plugin/tawembed/wysiwyg_taw.css";
	 iframeWin.document.getElementsByTagName('head')[0].appendChild(script);
*/

          }
        };
      } );

      editor.addCommand( 'TAWEmbed', new CKEDITOR.dialogCommand( 'TAWEmbedDialog' ) );

      editor.ui.addButton( 'TAWEmbed',
      {
        label: 'Embed Take Action Widget',
        command: 'TAWEmbed',
        icon: this.path + 'images/icon.gif'
      } );
    }
  } );
} )();
