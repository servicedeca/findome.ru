<div class="container-fluid container-fix about-header about-header-bigger" id="parallax" data-speed="3" data-type="background" style="background-image: url(<?php print $background;?>);">
  <div class="about-header-layer">
    <div class="container fin zero-padding">

      <div class="col-xs-2 comment-block-button <?php $user->uid == 0 ? print 'need-reg' : 0; ?>" <?php $user->uid != 0 ? print 'data-toggle="modal" data-target=".comment_modal"' : 0; ?>>
        <?php print $img_plus; ?>
        <p>Добавить отзыв</p>
      </div>

      <div class="col-xs-10 comment-block-text">
        <?php print $comments;?>
      </div>

    </div>
  </div>
</div>

<div class="modal fade comment_modal" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>Новый отзыв</p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>
    </div>

    <div class="col-xs-12 list-modal-city" id="info-box">
      <textarea class="comment-textarea realty-comment-form-input" rows="10" name="text" placeholder="Начните вводить текст здесь"></textarea>
    </div>

    <div class="col-xs-12 comment-points" id="like-comment">
      <h4>Оцените Ваш отзыв</h4>
      <div class="col-xs-6 text-right">
        <svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
             width="50px" height="50px" viewBox="0 0 200 200" enable-background="new 0 0 200 200" xml:space="preserve">
							<path class="top-fng" fill="#D3D3D3" d="M179.088,116.103c-6.348-10.871,8.839-16.104-4.262-26.266C158.32,77.035,159.39,79.032,123.69,78.629
							c-5.643-0.063-12.613,0.569-10.794-11.149c7.292-46.992-4.728-55.716-12.7-57.91c-16.784-4.618,3.531,14.646-17.484,50.721
							c-1.854,3.182-7.44,6.839-11.208,12.959c-7.778,12.633-15.256,32.572-21.714,32.572c-4.612,0-16.538,0-26.623,0v80.04
							c15.091-1.193,36.578-2.895,41.945-3.336c8.493-0.7,15.498,5.142,28.108,5.142c11.208,0,18.311,6.95,56.501,1.092
							c5.395-0.827,15.414-11.193,13.421-19.604c-1.537-6.494,16.795-11.597,12.839-23.464
							C171.331,131.743,187.994,131.354,179.088,116.103z"/>
						</svg>
      </div>
      <div class="col-xs-6 text-left">
        <svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
             width="50px" height="50px" viewBox="0 0 200 200" enable-background="new 0 0 200 200" xml:space="preserve">
						<path class="bottom-fng"  fill="#D3D3D3" d="M25.831,83.897c6.348,10.871-8.839,16.104,4.262,26.266c16.505,12.802,15.436,10.805,51.135,11.208
						c5.643,0.063,12.613-0.569,10.794,11.149c-7.292,46.992,4.728,55.716,12.7,57.91c16.784,4.618-3.531-14.646,17.484-50.721
						c1.854-3.182,7.44-6.839,11.208-12.959c7.778-12.633,15.256-32.572,21.714-32.572c4.612,0,16.538,0,26.623,0v-80.04
						c-15.091,1.193-36.578,2.895-41.945,3.336c-8.493,0.7-15.498-5.142-28.108-5.142c-11.208,0-18.311-6.95-56.501-1.092
						c-5.395,0.827-15.414,11.193-13.421,19.604c1.537,6.494-16.795,11.597-12.839,23.464C33.588,68.257,16.925,68.646,25.831,83.897z"/>
        </svg>
      </div>
    </div>

    <div class="col-xs-12 modal-button">
      <button type="button" class="ok-button show-buttom realty-comment-submit" aria-hidden="true" data-comment-pid="0" data-node-id="<?php print $node->nid;?>">Опубликовать отзыв</button>
      <button type="button" class="ok-button hide-buttom" data-dismiss="modal" aria-hidden="true">Закрыть</button>
    </div>
  </div>
</div>

<div class="modal fade comment_text" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p id="comment-author"></p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">
      <p class="cpp" id="comment-text"></p>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="ok-button" data-dismiss="modal" aria-hidden="true">Закрыть</button>
    </div>
  </div>
</div>

