/**
 * @file
 * Placemarks support plugin.
 */

(function($) {
  Drupal.behaviors.yamapsPlacemarks = {
    attach: function (context, settings) {
      ymaps.ready(function() {
        // Class for one placemark.
        $.yaMaps.YamapsPlacemark = function(geometry, properties, options) {
          this.placemark = new ymaps.Placemark(geometry, properties, options);

          this.parent = null;

          // Set placemark icon and balloon content.
          this.setContent = function(iconContent, balloonContent, entityid, tid) {
            this.placemark.properties.set('iconContent', iconContent);
            this.placemark.properties.set('balloonContentHeader', iconContent);
            this.placemark.properties.set('balloonContentBody', balloonContent);
            this.placemark.properties.set('entityid', entityid);
            this.placemark.properties.set('tid', tid);
          };

          // Set placemark color.
          this.setColor = function(color) {
            var preset = 'twirl#' + color;
            preset += this.placemark.properties.get('iconContent') ? 'StretchyIcon' : 'DotIcon';
            this.placemark.options.set('preset', preset)
          };

          // Close balloon.
          this.closeBalloon = function() {
            this.placemark.balloon.close();
          };

          // Open balloon.
          this.openBalloon = function() {
            this.placemark.balloon.open();
          };

          // Remove placemark.
          this.remove = function() {
            this.getParent().remove(this);
            this.exportParent();
          };

          // Set placemark parent.
          this.setParent = function(Parent) {
            this.parent = Parent;
          };

          // Get parent.
          this.getParent = function() {
            return this.parent;
          };

          // Export placemark information.
          this.export = function() {
            var coords = this.placemark.geometry.getCoordinates();
            var props = this.placemark.properties.getAll();
            return {
              coords: coords,
              params: {
                color: props.color,
                iconContent: props.iconContent,
                balloonContentBody: props.balloonContentBody,
                balloonContentHeader: props.iconContent,
                entityid: props.entityid,
                tid: props.tid
              }
            };
          };

          // Export all placemarks from this map.
          this.exportParent = function() {
            var collection = this.getParent();
            if (collection) {
              var mapId = collection.elements.getMap().container.getElement().parentElement.id;
              var placemarks = collection.export();
              var $storage = $('.field-yamaps-placemarks-' + mapId);
              $storage.val(JSON.stringify(placemarks));
            }
          };

          // Placemark events for export.
          this.placemark.events
            .add('dragend', this.exportParent, this)
            .add('propertieschange', this.exportParent, this);

          // Set placemark params.
          this.placemark.properties.set('Placemark', this);
          this.setColor(properties.color);
        };

        // Placemarks collection class.
        $.yaMaps.YamapsPlacemarkCollection = function(options) {
          this.placemarks = [];
          this.elements = new ymaps.GeoObjectCollection();
          this.elements.options.set(options);

          // Add new placemark to collection.
          this.add = function(Placemark) {
            Placemark.setParent(this);
            this.placemarks.push(Placemark);
            this.elements.add(Placemark.placemark);
            return Placemark;
          };

          // Create placemark and add to collection.
          this.createPlacemark = function(geometry, properties, options) {
            return this.add(new $.yaMaps.YamapsPlacemark(geometry, properties, options));
          };

          // Remove placemark.
          this.remove = function(Placemark) {
            this.elements.remove(Placemark.placemark);
            for (var i in this.placemarks) {
              if (this.placemarks[i] === Placemark) {
                this.placemarks.splice(i, 1);
                break;
              }
            }
          };

          // Each placemarks callback.
          this.each = function(callback) {
            for (var i in this.placemarks) {
              callback(this.placemarks[i]);
            }
          };

          // Export collection.
          this.export = function() {
            var placemarks = [];
            this.each(function(Placemark) {
              placemarks.push(Placemark.export());
            });
            return placemarks;
          };
        };

        // Edit placemark balloon template.
        $.yaMaps.addLayout('yamaps#PlacemarkBalloonEditLayout',
          ymaps.templateLayoutFactory.createClass(
            [
              '<div class="yamaps-balloon yamaps-placemark-edit">',
              '<div class="form-element">',
              '<label for="iconContent">' + Drupal.t('Placemark text') + '</label>',
              '<input type="text" id="iconContent" value="$[properties.iconContent]"/>',
              '</div>',
              '<div class="form-element placemark-colors">',
              '<label>' + Drupal.t('Color') + '</label>',
              '$[[yamaps#ColorPicker]]',
              '</div>',
              '<div class="form-element">',
              '<label for="balloonContent">' + Drupal.t('Balloon text') + '</label>',
              '<input type="text" id="balloonContent" value="$[properties.balloonContentBody]"/>',
              '<input type="text" style="display: none" id="entityid" value="$[properties.entityid]"/>',
              '<input type="text" style="display: none" id="tid" value="$[properties.tid]"/>',
              '</div>',
              '$[[yamaps#ActionsButtons]]',
              '</div>'
            ].join(""),
            {
              build: function () {
                this.constructor.superclass.build.call(this);
                this.properties = this.getData().properties.getAll();
                // Balloon HTML element.
                var $element = $(this.getParentElement());
                var _this = this;

                // Placemark colorpicker.
                this.$placemarkColors = $(this.getParentElement()).find('.placemark-colors .yamaps-color');
                this.$placemarkColors.each(function() {
                  var $this = $(this);
                  var $div = $this.children('div');
                  if (_this.properties.color == $div.attr('data-content')) {
                    $this.addClass('yamaps-color-active');
                  }
                });
                this.$placemarkColors.bind('click', this, this.colorClick);

                $('#edit-field-home-complex-und').change(function() {
                  var $complexid = $('#edit-field-home-complex-und').val();
                  //console.log(Map.options.placemarks);
                });

                // Placemark icon and balloon content.
                this.$iconContent = $element.find('#iconContent');
                this.$balloonContent = $element.find('#balloonContent');
                this.$entityid = $('#edit-field-home-complex-und').val();
                this.$tid = $('#edit-field-home-complex-und').val();

                // Actions.
                $('#deleteButton').bind('click', this, this.onDeleteClick);
                $('#saveButton').bind('click', this, this.onSaveClick);
              },
              clear: function () {
                this.constructor.superclass.build.call(this);
                this.$placemarkColors.unbind('click', this, this.colorClick);
                $('#deleteButton').unbind('click', this, this.onDeleteClick);
                $('#saveButton').unbind('click', this, this.onSaveClick);

              },
              colorClick: function(e) {
                // Colorpicker click.
                e.data.properties.color = $(this).children('div').attr('data-content');
              },
              onDeleteClick: function (e) {
                // Delete click.
                e.data.properties.Placemark.remove();
                e.preventDefault();
              },
              onSaveClick: function(e) {
                // Save click.
                var placemark = e.data.properties.Placemark;
                // Save content, color and close balloon.
                placemark.setContent(e.data.$iconContent.val(), e.data.$balloonContent.val(), e.data.$entityid, e.data.$tid );
                placemark.setColor(e.data.properties.color);
                placemark.closeBalloon();
              }
            }
          )
        );


        // Add placemarks support to map.
        $.yaMaps.addMapTools(function(Map) {
          // Default options.
          var options = {
            balloonMaxWidth: 300,
            balloonCloseButton: true
          };
          if (Map.options.edit) {
            // If map in edit mode set edit mode to placemarks options.
            options.balloonContentLayout = 'yamaps#PlacemarkBalloonEditLayout';
            options.draggable = true;
          }

          // Create new collection.
          var placemarksCollection = new $.yaMaps.YamapsPlacemarkCollection(options);

          // Add already created elements to collection.
          for (var i in Map.options.placemarks) {
            placemarksCollection.add(new $.yaMaps.YamapsPlacemark(Map.options.placemarks[i].coords, Map.options.placemarks[i].params, Map.options.placemarks[i].options));
          }

          var clustererIcons = [{
            href: '/'+Drupal.settings.REALTY_FRONT_THEME_PATH+'/images/claster2.svg',
            size: [47, 47],
            offset: [-23, -23]
          },
            {
              href:'/'+Drupal.settings.REALTY_FRONT_THEME_PATH+'/images/claster2.svg',
              size: [47, 47],
              offset: [-23, -23]
            }
          ];

          MyIconContentLayout = ymaps.templateLayoutFactory.createClass(
            '<div style="color: #ffffff; font-size:16px ;font-weight:300;">$[properties.geoObjects.length]</div>')

          var clusterer = new ymaps.Clusterer({
            clusterIcons: clustererIcons,
            gridSize: 100,
            clusterIconContentLayout: MyIconContentLayout
          });
          var clustererr = new ymaps.Clusterer({
            clusterIcons: clustererIcons,
            gridSize: 100,
            clusterIconContentLayout: MyIconContentLayout
          });

          $('#edit-field-home-complex-und').change(function() {
            var $complexid = $('#edit-field-home-complex-und').val();
            $('#entityid').val($complexid);
            $('#saveButton').trigger('click');
          });

          var GetDataComplex = function(complexID) {
            $.ajax({
              url: '/get_data_complex',
              type: 'POST',
              data: {
                nid: complexID
              },
              success: function(answer) {
                var object = jQuery.parseJSON(answer);
                $('#ajax-map-balloon-image').html('');
                if (object.image) {
                  $('#ajax-map-balloon-image').html(object.image);
                }
                $('#ajax-map-balloon-logo').html('');
                if (object.logo) {
                  $('#ajax-map-balloon-logo').html(object.logo);
                }
                $('#ajax-map-balloon-title').html('');
                if (object.title) {
                  $('#ajax-map-balloon-title').html(object.title);
                }
                $('#ajax-map-balloon-description').html('');
                if (object.description) {
                  $('#ajax-map-balloon-description').html(object.description);
                }
                $('#ajax-map-balloon-details').html('');
                if (object.details) {
                  $('#ajax-map-balloon-details').html(object.details);
                }
              },
              error: function(response) {
                alert('false');
              }
            });
          }

          var Placemarks = [];
          /*
           /**-----**/

          var lenghtMarks = Map.options.placemarks.length;
          if(lenghtMarks%2 == 0 && Map.options.placemarks[0].params.tid == Map.options.placemarks[lenghtMarks/2].params.tid) {
            Map.options.placemarks.splice(lenghtMarks/2, lenghtMarks/2)
          }
          /**-----**/

          for (var i in Map.options.placemarks) {
            var Coords = Map.options.placemarks[i].coords;
            var Params = Map.options.placemarks[i].params;
            var Icon = Map.options.placemarks[i].icon;
            var Placemark = new ymaps.Placemark(Coords, Params, {
              // Опции.
              // Необходимо указать данный тип макета.
              iconLayout: 'default#image',
              // Своё изображение иконки метки.
              iconImageHref: '/'+Drupal.settings.REALTY_FRONT_THEME_PATH+'/images/mark2.svg',
              // Размеры метки.
              iconImageSize: [30, 42],
              // Смещение левого верхнего угла иконки относительно
              // её "ножки" (точки привязки).
              iconImageOffset: [-3, -42]
            });
            Map.options.placemarks[i].params.balloonContentHeader = Map.options.placemarks[i].params.iconContent;
            Map.options.placemarks[i].params.iconContent = '';
            if(Map.options.placemarks[i].coords) {
              Placemarks.push(Placemark);
            }
          }

          clusterer.add(Placemarks);


          // Add collection to the map
          if (!Map.options.edit) {
            Map.map.geoObjects.add(clusterer);

            var centerAndZoom =  ymaps.util.bounds.getCenterAndZoom(

              clusterer.getBounds(),

              Map.map.container.getSize(),

              Map.map.options.get('projection')

            );
            Map.map.setCenter(centerAndZoom.center, 11);

            //zoom layout


            ZoomLayout = ymaps.templateLayoutFactory.createClass("<div>" +
              "<div style='cursor: pointer' class='zoom-in' id='zoom-in'>" +
              "<img src='/"+Drupal.settings.REALTY_FRONT_THEME_PATH + "/images/map_element-06.png'> " +
              "</div><br>" +
              "<div style='cursor: pointer' class='zoom-out' id='zoom-out'>" +
              "<img src='/"+Drupal.settings.REALTY_FRONT_THEME_PATH + "/images/map_element_Artboard_19.png'>" +
              "</div>" +
              "</div>", {

              // Переопределяем методы макета, чтобы выполнять дополнительные действия
              // при построении и очистке макета.
              build: function () {
                // Вызываем родительский метод build.
                ZoomLayout.superclass.build.call(this);

                // Привязываем функции-обработчики к контексту и сохраняем ссылки
                // на них, чтобы потом отписаться от событий.
                this.zoomInCallback = ymaps.util.bind(this.zoomIn, this);
                this.zoomOutCallback = ymaps.util.bind(this.zoomOut, this);

                // Начинаем слушать клики на кнопках макета.
                $('#zoom-in').bind('click', this.zoomInCallback);
                $('#zoom-out').bind('click', this.zoomOutCallback);
              },

              clear: function () {
                // Снимаем обработчики кликов.
                $('#zoom-in').unbind('click', this.zoomInCallback);
                $('#zoom-out').unbind('click', this.zoomOutCallback);

                // Вызываем родительский метод clear.
                ZoomLayout.superclass.clear.call(this);
              },

              zoomIn: function () {
                var map = this.getData().control.getMap();
                // Генерируем событие, в ответ на которое
                // элемент управления изменит коэффициент масштабирования карты.
                this.events.fire('zoomchange', {
                  oldZoom: map.getZoom(),
                  newZoom: map.getZoom() + 1
                });
              },

              zoomOut: function () {
                var map = this.getData().control.getMap();
                this.events.fire('zoomchange', {
                  oldZoom: map.getZoom(),
                  newZoom: map.getZoom() - 1
                });
              }
            })

            var zoomControl = new ymaps.control.SmallZoomControl({ layout: ZoomLayout});

            Map.map.controls.add(zoomControl, {right: 10, top: 75});


          } else {
            Map.map.geoObjects.add(placemarksCollection.elements);

          }

          Map.map.geoObjects.events.add('click', function (e) {
            var entityid = e.get('target').properties.get('entityid');
            if(entityid) {
              GetDataComplex(entityid);
            }
          });

          var placmark_filter = function(obj) {
            clusterer.removeAll();

            if (obj) {
              var Placemarks = [];

              /**-----**/
              var lenghtMarks = Map.options.placemarks.length;
              if(lenghtMarks%2 == 0 && Map.options.placemarks[0].params.tid == Map.options.placemarks[lenghtMarks/2].params.tid) {
                Map.options.placemarks.splice(lenghtMarks/2, lenghtMarks/2)
              }
              /**-----**/


              for (var i in obj) {
                if (obj[i].params && obj[i].coords) {
                  var Coords = obj[i].coords;
                  var Params = obj[i].params;
                  //var Icon = Map.options.placemarks[i].icon;
                  var Placemark = new ymaps.Placemark(Coords, Params, {
                    // Опции.
                    // Необходимо указать данный тип макета.
                    iconLayout: 'default#image',
                    // Своё изображение иконки метки.
                    iconImageHref: '/' + Drupal.settings.REALTY_FRONT_THEME_PATH + '/images/mark2.svg',
                    // Размеры метки.
                    iconImageSize: [30, 47],
                    // Смещение левого верхнего угла иконки относительно
                    // её "ножки" (точки привязки).
                    iconImageOffset: [-3, -42]
                  });
                  obj[i].params.iconContent = '';
                  Placemarks.push(Placemark);
                }
              }

              clusterer.add(Placemarks);
              Map.map.geoObjects.add(clusterer);
              var centerAndZoom =  ymaps.util.bounds.getCenterAndZoom(

                clusterer.getBounds(),

                Map.map.container.getSize(),

                Map.map.options.get('projection')

              );
              //Map.map.setCenter(centerAndZoom.center, 11);
              Map.map.panTo(centerAndZoom.center, {
                flying: 1
              });
            }
          }

          var areaArray = new Array();
          var developerArray = new Array();
          var complexArray = new Array();
          var categoryArray = new Array();
          var stock = 'All';
          var city = $('#div-map-block').data('city-id');

          var get_placemarks_filter = function() {

            $.ajax({
              url: '/search_map',
              type: 'POST',
              data: {
                city: city,
                area: areaArray,
                developer: developerArray,
                complex: complexArray,
                category: categoryArray,
                stock: stock
              },
              success: function(answer) {
                if(answer){

                  var object = jQuery.parseJSON(answer);

                  placmark_filter(object);
                }
                else {
                  placmark_filter(null);
                }
              },
              error: function(answer) {
                alert('false');
              }
            });
          }


          $('.CheckboxMapArea').click(function() {
            var value = $(this).val().split(';');

            if ($(this).prop("checked") == false) {
              areaArray.push(value[0]);
            } else {
              for (var i = 0; i < areaArray.length; i++) {
                if (areaArray[i] == value[0]) {
                  areaArray.splice(i, 1);
                }
              }
            }
            get_placemarks_filter();
          });

          $('.CheckboxMapCategory').click(function() {
            var value = $(this).val().split(';');

            if ($(this).prop("checked") == false) {
              categoryArray.push(value[0]);
            } else {
              for (var i = 0; i < categoryArray.length; i++) {
                if (categoryArray[i] == value[0]) {
                  categoryArray.splice(i, 1);
                }
              }
            }
            get_placemarks_filter();
          });

          $('.CheckboxMapDeveloper').click(function() {
            var value = $(this).val().split(';');

            if ($(this).prop("checked") == false) {
              developerArray.push(value[0]);
            } else {
              for (var i = 0; i < developerArray.length; i++) {
                if (developerArray[i] == value[0]) {
                  developerArray.splice(i, 1);
                }
              }
            }
            get_placemarks_filter();
          });

          $('.CheckboxMapComplex').click(function() {
            var value = $(this).val().split(';');

            if ($(this).prop("checked") == false) {
              complexArray.push(value[0]);
            } else {
              for (var i = 0; i < complexArray.length; i++) {
                if (complexArray[i] == value[0]) {
                  complexArray.splice(i, 1);
                }
              }
            }
            get_placemarks_filter();
          });

          $('#mapcheck').click(function() {
            $(this).prop("checked") == false ? stock = 1 : stock = 'All';
            get_placemarks_filter();
          });

          // If map in edit mode add search form.
          var $searchForm = $([
            '<form class="yamaps-search-form">',
            '<input type="text" class="form-text" placeholder="' + Drupal.t('Search on the map') + '" value=""/>',
            '<input type="submit" class="form-submit" value="' + Drupal.t('Search') + '"/>',
            '</form>'].join(''));

          $searchForm.bind('submit', function (e) {
            var searchQuery = $searchForm.children('input').val();
            // Find one element.
            ymaps.geocode(searchQuery, {results: 1}, {results: 100}).then(function (res) {
              var geoObject = res.geoObjects.get(0);
              if (!geoObject) {
                alert(Drupal.t('Not found'));
                return;
              }
              var coordinates = geoObject.geometry.getCoordinates();
              var params = geoObject.properties.getAll();
              // Create new placemark.
              var Placemark = new $.yaMaps.YamapsPlacemark(coordinates, {
                iconContent: params.name,
                balloonHeaderContent: params.name,
                balloonContentBody: params.description,
                color: 'white'
              });
              placemarksCollection.add(Placemark);
              Placemark.openBalloon();
              // Pan to new placemark.
              Map.map.panTo(coordinates, {
                checkZoomRange: false,
                delay: 0,
                duration: 1000,
                flying: true
              });
            });
            e.preventDefault();
          });
          // Add search form after current map.
          $searchForm.insertAfter('#' + Map.mapId);
          // Map click listener to adding new placemark.
          var mapClick = function(event) {
            var Placemark = placemarksCollection.createPlacemark(event.get('coordPosition'), {iconContent: '', color: 'blue', balloonContentBody: '', balloonContentHeader: '', entityid: '',tid: '' });
            Placemark.openBalloon();
          };

          if (!Map.options.edit) {

          }
          else {
            // New button.
            var pointButton = new ymaps.control.Button({
              data: {
                content: '<ymaps class="ymaps-b-form-button__text"><ymaps class="ymaps-b-ico ymaps-b-ico_type_point"></ymaps></ymaps>',
                title: Drupal.t('Setting points')
              }
            });

            // Button events.
            pointButton.events
              .add('select', function(event) {
                Map.cursor = Map.map.cursors.push('pointer');
                Map.mapListeners.add('click', mapClick);
              })
              .add('deselect', function(event) {
                Map.cursor.remove();
                Map.mapListeners.remove('click', mapClick);
              });

            return pointButton;
          }
        });
      });
    }
  }
})(jQuery);
