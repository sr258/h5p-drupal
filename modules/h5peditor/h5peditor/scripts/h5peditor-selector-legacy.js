var H5PEditor = H5PEditor || {};
var ns = H5PEditor;

/**
 * @class
 * @alias H5PEditor.SelectorLegacy
 * @implements {ContentTypeSelector}
 */
ns.SelectorLegacy = function (data, library, defaultParams) {
  var self = this;

  // Load libraries list
  $.ajax({
    dataType: 'json',
    url: ns.getAjaxUrl('libraries')
  }).fail(function () {
    self.$element = $('<div>Error, unable to load libraries.</div>');
  }).done(function (data) {
    self.selector = new LibrarySelector(data, library, defaultParams);
    self.selector.appendTo($container.html(''));
    if (library) {
      self.selector.$selector.change();
    }
  });
};

/**
 * Returns the html element for the hub
 *
 * @public
 * @return {HTMLElement}
 */
ns.SelectorLegacy.prototype.getElement = function(){

};

/**
 * Registers a listener for select events
 *
 * @param {function} callback
 * @param {object} scope
 */
ns.SelectorLegacy.prototype.onSelect = function(callback, scope) {

};