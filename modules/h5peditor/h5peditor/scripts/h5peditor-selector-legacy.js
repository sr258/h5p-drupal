var H5PEditor = H5PEditor || {};
var ns = H5PEditor;

/**
 * @class
 * @alias H5PEditor.SelectorLegacy
 * @implements {ContentTypeSelector}
 */
ns.SelectorLegacy = function (data, library, defaultParams) {
  var self = this;
  var LibrarySelector = ns.LibrarySelector;

  // create root element
  this.element = document.createElement('div');

  // Load libraries list
  ns.$.ajax({
    dataType: 'json',
    url: ns.getAjaxUrl('libraries')
  }).fail(function () {
    self.element.innerHTML = 'Error, unable to load libraries.';
  }).done(function (data) {
    self.selector = new LibrarySelector(data, library, defaultParams);
    self.selector.appendTo(ns.$(self.element));
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
  return this.element;
};

/**
 * Registers a listener for select events
 *
 * @param {function} callback
 * @param {object} scope
 */
ns.SelectorLegacy.prototype.onSelect = function(callback, scope) {
};