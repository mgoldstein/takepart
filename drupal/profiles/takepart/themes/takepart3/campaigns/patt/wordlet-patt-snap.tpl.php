	<script type="text/javascript" src="//ct1.addthis.com/static/r07/auth011.js"></script>
	<link rel="stylesheet" type="text/css" href="//ct1.addthis.com/static/r07/widget103.css" media="all">

        <!-- link rel="stylesheet" href="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/css/normalize.min.css" -->
        <link rel="stylesheet" href="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/css/main.css">




				<div id="snap-grid">
	                <div id="snap-grid-container">
	                	
	                </div>
	                <div id="grid-modal" class="modal">
	               		<div class="modal-left">
	               			<img src="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/photo-sarah-parker-full.jpg" alt="Full Image" />
	               		</div>
	               		<div class="modal-right">
	               			<div id="modal-content">
		               			<div class="close-btn"><img src="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/close-btn.jpg" alt="Close" /></div>
		               			<h1></h1>
		               			<h2></h2>
		               			<h3></h3>
		               			<div class="description"></div>
	               			</div>
	               			<footer>
	               				<div class="modal-nav">
	               					<div id="nav-left" class="nav-button"><img src="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/nav-arrow-left.jpg" alt="Left" /></div>
	               					<div id="nav-right" class="nav-button"><img src="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/nav-arrow-right.jpg" alt="right" /></div>
	               				</div>
	               				<div id="social-buttons">
	               					<div class="addthis_toolbox addthis_default_style addthis_32x32_style thank-you-addthis" nid="28177">
									  <a class="addthis_button_facebook social-icon"></a>
									  <a class="addthis_button_twitter social-icon"></a>
									  <!-- <a class="addthis_button_google_plusone" g:plusone:size="standard" g:plusone:annotation="none" title="Share on Google+1"></a> -->
									  <a class="addthis_button_email"></a>
									</div>
	               				</div>
	               				<div id="share-btn">SHARE</div>
	               			</footer>
	               		</div>
	                </div>
                </div>
                
                <!-- <article>
                    <header>
                        <h1>article header h1</h1>
                        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam sodales urna non odio egestas tempor. Nunc vel vehicula ante. Etiam bibendum iaculis libero, eget molestie nisl pharetra in. In semper consequat est, eu porta velit mollis nec.</p>
                    </header>
                    <section>
                        <h2>article section h2</h2>
                        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam sodales urna non odio egestas tempor. Nunc vel vehicula ante. Etiam bibendum iaculis libero, eget molestie nisl pharetra in. In semper consequat est, eu porta velit mollis nec. Curabitur posuere enim eget turpis feugiat tempor. Etiam ullamcorper lorem dapibus velit suscipit ultrices. Proin in est sed erat facilisis pharetra.</p>
                    </section>
                    <section>
                        <h2>article section h2</h2>
                        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam sodales urna non odio egestas tempor. Nunc vel vehicula ante. Etiam bibendum iaculis libero, eget molestie nisl pharetra in. In semper consequat est, eu porta velit mollis nec. Curabitur posuere enim eget turpis feugiat tempor. Etiam ullamcorper lorem dapibus velit suscipit ultrices. Proin in est sed erat facilisis pharetra.</p>
                    </section>
                    <footer>
                        <h3>article footer h3</h3>
                        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam sodales urna non odio egestas tempor. Nunc vel vehicula ante. Etiam bibendum iaculis libero, eget molestie nisl pharetra in. In semper consequat est, eu porta velit mollis nec. Curabitur posuere enim eget turpis feugiat tempor.</p>
                    </footer>
                </article> -->

<script>
$ = jQuery;
</script>

 <!--script src="https://clients.midnightoilcreative.com/clients/participantmedia/gallery/js/main.js"></script -->

 <script>


$(document).ready(function () {
    // start module!
    snapGallery.init();
});

var snapGallery = (function(){
    
    
    var dataURL = "json/snapgriddata.json";
    
    var appendToElement = "#snap-grid-container";
    var modalID = "#grid-modal";
    
    var imagePath = "https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/";
    
    // module data
    var data = null;
    var tiles = [];
    var profiles = [];
    
    var curIndex = 0;
        
    
    // load JSON data for grid
    function loadData(){
        request = {
            
        }
        
        //start the ajax
        $.ajax({
            //this is the php file that processes the data and send mail
            url: "json/snapgriddata.txt", 
            //GET method is used
            type: "GET",
            //data type
            dataType: "json",
            //pass the data         
            data: request,     
            //Do not cache the page
            cache: false,
            //success
            success: function (json) {              
                //if process.php returned 1/true (send mail success)
                
                data = json;
                console.log('json: ' + data.snapgrid.tiles[0].type);
                
                initGrid();
                          
            },
            
            error: function(error, msg, errThrown){

                //showUserState('error');
                console.log('load error ' + msg + " " + errThrown);                
                
            }       
        });
        
    }
    
    function initGrid(){
        console.log('initializing grid');
        
        tiles = data.snapgrid.tiles;
        var numTiles = tiles.length;
        
        //var html = "<div class='tile'></div>"
        
        console.log('numTiles ' + numTiles);
        
        for(var i=0; i<numTiles; i++){
            
           var tile = tiles[i];
           var $tile = $("<div class='tile' >");
           
           switch(tile.type) {
               
               case "photo":
                    
                    $tile.append("<img src='https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/"+tile.thumb+"' alt='' />");
                    
                    $tile.click({ tileIndex: i }, showModal);
                    $tile.css('cursor', 'pointer');
                    profiles.push(tile);
                    
                    
                    break;
                    
               case "fact":
                    $tile.append("<img src='https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/"+tile.questionImg+"' alt='' />");
                    
                    $tile.click({ tileIndex: i }, showFactAnswer);
                    $tile.css('cursor', 'pointer');
               
                    break;
                    
               case "link":
                    $tile.append("<a href='"+ tile.link + "' target='"+ "_blank" + "' ><img src='https://clients.midnightoilcreative.com/clients/participantmedia/gallery/img/"+tile.image+"' alt='Image' /></a>");
                                                           
                    $tile.css('cursor', 'pointer');
                    
                    break;
                    
               default:
               
                    break;
               
           }
           $tile.append('</div>');
           $tile.css('background-color', '#FFFF00');
           $(appendToElement).append($tile);
            
        }
        
        // button bindings
        $('.close-btn').click(hideModal);
        
        $('#nav-right').click(showNextProfile);
        $('#nav-left').click(showPrevProfile);
        
        $('#share-btn').click(function(){
           $('#social-buttons').show(); 
        });
        
    }
    
    /*
     * Show modal pop over
     */
    function showModal(event){
        console.log('clicked tile index - '+event.data.tileIndex);
        var index = event.data.tileIndex;
        
        $('#social-buttons').hide();
        populateProfile(index);
        //$(modalID).show();
        $(modalID).fadeIn();
    }
    
    /**
     * 
     */
    function showFactAnswer(event){
        var index = event.data.tileIndex;
        var answer = tiles[index].answerImg;
        var element = event.target;
        console.log('element ' + element);
        $(element).attr('src', imagePath+answer);
        $(element).parent().css('cursor', 'auto');
    }
    
    /**
     * 
     */
    function populateProfile(index){
        
        var tile = tiles[index];
                
        $('#modal-content > h1').text(tile.name);
        $('#modal-content > h2').text(tile.role);
        $('#modal-content > h3').text(tile.location);
        $('#modal-content > div.description').text(tile.description);
        $('.modal-left > img').attr('src', imagePath+tile.photo);
        
        curIndex = index;
    }
    
    /*
     * Hide modal pop over
     */
    function hideModal(event){
        $(modalID).fadeOut();
    }
    
    /*
     * 
     */
    function showNextProfile(event){
        var profilesTotal = profiles.length;
        var tilesTotal = tiles.length;
        var tileType = tiles[curIndex].type;
        
        do{
            curIndex++;
                      
            if(curIndex > tilesTotal-1){
                curIndex = 0;
            }
            
            tileType = tiles[curIndex].type;
        }
        while( tileType != "photo")
                
        
        populateProfile(curIndex);
    }
    
    /*
     * 
     */
    function showPrevProfile(event){
        var profilesTotal = profiles.length;
        var tilesTotal = tiles.length;
        var tileType = tiles[curIndex].type;
        
        do{
            curIndex--;
                      
            if(curIndex < 0){
                curIndex = tilesTotal-1;
            }
            
            tileType = tiles[curIndex].type;
        }
        while( tileType != "photo")
                
        
        populateProfile(curIndex);
    }
    
    // publicly exposed functions
    return {
        /**
         * initialize module
         */
        init: function(){
            loadData();
        }
    }
     
    
})();



</script>