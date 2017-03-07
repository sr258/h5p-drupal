var H5PEditor = H5PEditor || {};
var ns = H5PEditor;

/**
 * @class
 * @alias H5PEditor.SelectorHub
 * @implements {ContentTypeSelector}
 */
ns.SelectorHub = function () {
  this.client = new H5P.HubClient({
    apiRootUrl: H5PEditor.ajaxPath
  });
};

/**
 * Returns the html element for the hub
 *
 * @public
 * @return {HTMLElement}
 */
ns.SelectorHub.prototype.getElement = function(){
  return this.client.getElement();
};

/**
 * Registers a listener for select events
 *
 * @param {function} callback
 * @param {object} scope
 */
ns.SelectorHub.prototype.onSelect = function(callback, scope) {
  this.client.on('select', function (event) {
    this.client.getContentType(event.id)
      .then(this.createContentTypeId)
      .then(function(contentTypeId){
        callback.call(scope || this, contentTypeId)
      });
  }, this);
};

/**
 * Takes a content type, and extracts the full id (ubername)
 *
 * @param {ContentType} contentType
 *
 * @private
 * @return {string}
 */
ns.SelectorHub.prototype.createContentTypeId = function (contentType) {
  return contentType.machineName + ' ' + contentType.majorVersion + '.' + contentType.minorVersion;
};