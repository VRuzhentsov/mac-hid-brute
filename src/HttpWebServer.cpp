#include "HttpWebServer.h"

const bool OTA_UPDATE_ENABLED = true;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
  <head>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/vendors~app~embed~sandbox~sandbox-startup.7424373eb.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/vendors~app~embed~sandbox-startup.b754f8b0e.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/default~app~embed~sandbox~sandbox-startup.b2134d8a8.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/sandbox-startup.a6840230d.js"></script>
    <script src="//codesandbox.io/static/browserfs12/browserfs.min.js" type="text/javascript"></script>
    <script>
      window.process = BrowserFS.BFSRequire('process');
      window.Buffer = BrowserFS.BFSRequire('buffer').Buffer;
    </script>
    <meta charset="utf-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"/>
    <meta name="theme-color" content="#000000"/>
    <!--
      manifest.json provides metadata used when your web app is added to the
      homescreen on Android. See https://developers.google.com/web/fundamentals/engage-and-retain/web-app-manifest/
    -->
    <link rel="manifest" href="/manifest.json"/>
    <link rel="shortcut icon" href="/favicon.ico"/>
    <script src="https://kit.fontawesome.com/228dfc1a0b.js" crossorigin="anonymous"></script>
    <!--
      Notice the use of  in the tags above.
      It will be replaced with the URL of the `public` folder during the build.
      Only files inside the `public` folder can be referenced from the HTML.

      Unlike "/favicon.ico" or "favicon.ico", "/favicon.ico" will
      work correctly both with client-side routing and a non-root public URL.
      Learn how to configure a non-root public URL by running `npm run build`.
    -->
    <title>React App</title>
    <link rel="manifest" href="/manifest.json">
  </head>
  <body>
    <noscript>You need to enable JavaScript to run this app.
    </noscript>
    <div id="root"></div>
    <!--
      This HTML file is a template.
      If you open it directly in the browser, you will see an empty page.

      You can add webfonts, meta tags, or analytics to this file.
      The build step will place the bundled scripts into the <body> tag.

      To begin the development, run `npm start` or `yarn start`.
      To create a production bundle, use `npm run build` or `yarn build`.
    -->
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/vendors~app~codemirror-editor~monaco-editor~sandbox.ad4e6d3c4.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/common-sandbox.d3049e87f.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/vendors~app~sandbox.aca52037e.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/vendors~sandbox.3bd3135bd.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/default~app~embed~sandbox.d94c26d71.chunk.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/sandbox.df283ba5e.js"></script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/banner.0b5d84a2b.js"></script>
    <script>
      window.__SANDBOX_DATA__ = {
        data: {
          "transpiledModules": {
            "/src/Todo.css:": {
              "query": "",
              "module": {
                "path": "/src/Todo.css",
                "code": ".Todo {\r\n  display: flex;\r\n  margin: 0 -3rem 4px;\r\n  padding: 1.1rem 3rem;\r\n  justify-content: space-between;\r\n  align-items: center;\r\n  background: rgba(255, 255, 255, 0.1);\r\n}\r\n\r\n.Todo-task {\r\n  position: relative;\r\n  transition: opacity 0.4s linear;\r\n}\r\n\r\n.Todo-task.completed {\r\n  opacity: 0.6;\r\n}\r\n\r\n.Todo-task.completed:before {\r\n  content: \"\";\r\n  position: absolute;\r\n  top: 50%;\r\n  left: -0.5rem;\r\n  display: block;\r\n  width: 0%;\r\n  height: 2px;\r\n  background: #fff;\r\n  animation: strikeitem 0.5s ease-out 0s forwards;\r\n}\r\n\r\n@keyframes strikeitem {\r\n  to {\r\n    width: calc(100% + 1rem);\r\n  }\r\n}\r\n\r\n.Todo-buttons {\r\n  flex-shrink: 0;\r\n  padding-left: 0.7em;\r\n}\r\n\r\n.Todo-buttons button {\r\n  border: none;\r\n  font-size: 1em;\r\n  margin: 0.4em;\r\n  background: none;\r\n  -webkit-appearance: none;\r\n  cursor: pointer;\r\n  color: #fff;\r\n}\r\n\r\n.Todo-edit-form {\r\n  display: flex;\r\n  flex-wrap: wrap;\r\n}\r\n\r\n.Todo-edit-form label {\r\n  min-width: 100%;\r\n  margin-bottom: 0.5rem;\r\n  font-size: 1.3rem;\r\n}\r\n\r\n.Todo-edit-form input {\r\n  flex-grow: 1;\r\n  border: none;\r\n  background: #f7f1f1;\r\n  padding: 0 1.5em;\r\n  font-size: initial;\r\n}\r\n\r\n.Todo-edit-form button {\r\n  padding: 0 1.3rem;\r\n  border: none;\r\n  background: #ff6666;\r\n  color: white;\r\n  text-transform: uppercase;\r\n  font-weight: bold;\r\n  border: 1px solid rgba(255, 255, 255, 0.3);\r\n  margin-left: 5px;\r\n  cursor: pointer;\r\n  transform: background 0.2s ease-out;\r\n}\r\n\r\n.Todo-edit-form button:hover {\r\n  background: #ff5e5e;\r\n}\r\n\r\n.Todo-edit-form input,\r\n.Todo-edit-form button {\r\n  font-family: \"Quicksand\", sans-serif;\r\n  height: 3rem;\r\n}\r\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": [],
              "initiators": ["/src/Todo.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/Todo.css",
                "compiledCode": "\nfunction createStyleNode(id, content) {\n  var styleNode =\n    document.getElementById(id) || document.createElement('style');\n\n  styleNode.setAttribute('id', id);\n  styleNode.type = 'text/css';\n  if (styleNode.styleSheet) {\n    styleNode.styleSheet.cssText = content;\n  } else {\n    styleNode.innerHTML = '';\n    styleNode.appendChild(document.createTextNode(content));\n  }\n  document.head.appendChild(styleNode);\n}\n\ncreateStyleNode(\n  \"/src/Todo.css:-css\",\n  \".Todo {\\r\\n  display: flex;\\r\\n  margin: 0 -3rem 4px;\\r\\n  padding: 1.1rem 3rem;\\r\\n  justify-content: space-between;\\r\\n  align-items: center;\\r\\n  background: rgba(255, 255, 255, 0.1);\\r\\n}\\r\\n\\r\\n.Todo-task {\\r\\n  position: relative;\\r\\n  transition: opacity 0.4s linear;\\r\\n}\\r\\n\\r\\n.Todo-task.completed {\\r\\n  opacity: 0.6;\\r\\n}\\r\\n\\r\\n.Todo-task.completed:before {\\r\\n  content: \\\"\\\";\\r\\n  position: absolute;\\r\\n  top: 50%;\\r\\n  left: -0.5rem;\\r\\n  display: block;\\r\\n  width: 0%;\\r\\n  height: 2px;\\r\\n  background: #fff;\\r\\n  animation: strikeitem 0.5s ease-out 0s forwards;\\r\\n}\\r\\n\\r\\n@keyframes strikeitem {\\r\\n  to {\\r\\n    width: calc(100% + 1rem);\\r\\n  }\\r\\n}\\r\\n\\r\\n.Todo-buttons {\\r\\n  flex-shrink: 0;\\r\\n  padding-left: 0.7em;\\r\\n}\\r\\n\\r\\n.Todo-buttons button {\\r\\n  border: none;\\r\\n  font-size: 1em;\\r\\n  margin: 0.4em;\\r\\n  background: none;\\r\\n  -webkit-appearance: none;\\r\\n  cursor: pointer;\\r\\n  color: #fff;\\r\\n}\\r\\n\\r\\n.Todo-edit-form {\\r\\n  display: flex;\\r\\n  flex-wrap: wrap;\\r\\n}\\r\\n\\r\\n.Todo-edit-form label {\\r\\n  min-width: 100%;\\r\\n  margin-bottom: 0.5rem;\\r\\n  font-size: 1.3rem;\\r\\n}\\r\\n\\r\\n.Todo-edit-form input {\\r\\n  flex-grow: 1;\\r\\n  border: none;\\r\\n  background: #f7f1f1;\\r\\n  padding: 0 1.5em;\\r\\n  font-size: initial;\\r\\n}\\r\\n\\r\\n.Todo-edit-form button {\\r\\n  padding: 0 1.3rem;\\r\\n  border: none;\\r\\n  background: #ff6666;\\r\\n  color: white;\\r\\n  text-transform: uppercase;\\r\\n  font-weight: bold;\\r\\n  border: 1px solid rgba(255, 255, 255, 0.3);\\r\\n  margin-left: 5px;\\r\\n  cursor: pointer;\\r\\n  transform: background 0.2s ease-out;\\r\\n}\\r\\n\\r\\n.Todo-edit-form button:hover {\\r\\n  background: #ff5e5e;\\r\\n}\\r\\n\\r\\n.Todo-edit-form input,\\r\\n.Todo-edit-form button {\\r\\n  font-family: \\\"Quicksand\\\", sans-serif;\\r\\n  height: 3rem;\\r\\n}\\r\\n\"\n);\n\n\n",
                "sourceEqualsCompiled": false
              }
            },
            "/src/Todo.js:": {
              "query": "",
              "module": {
                "path": "/src/Todo.js",
                "code": "import React, { useState } from \"react\";\r\nimport ReactDOM from \"react-dom\";\r\nimport \"./Todo.css\";\r\n\r\nfunction Todo({ todo, remove, update, toggleComplete }) {\r\n  const [isEditing, setIsEditing] = useState(false);\r\n  const [task, setTask] = useState(todo.task);\r\n\r\n  const handleClick = evt => {\r\n    remove(evt.target.id);\r\n  };\r\n  const toggleFrom = () => {\r\n    setIsEditing(!isEditing);\r\n  };\r\n  const handleUpdate = evt => {\r\n    evt.preventDefault();\r\n    update(todo.id, task);\r\n    toggleFrom();\r\n  };\r\n  const handleChange = evt => {\r\n    setTask(evt.target.value);\r\n  };\r\n  const toggleCompleted = evt => {\r\n    toggleComplete(evt.target.id);\r\n  };\r\n\r\n  let result;\r\n  if (isEditing) {\r\n    result = (\r\n      \u003cdiv className=\"Todo\">\r\n        \u003cform className=\"Todo-edit-form\" onSubmit={handleUpdate}>\r\n          \u003cinput onChange={handleChange} value={task} type=\"text\" />\r\n          \u003cbutton>Save\u003c/button>\r\n        \u003c/form>\r\n      \u003c/div>\r\n    );\r\n  } else {\r\n    result = (\r\n      \u003cdiv className=\"Todo\">\r\n        \u003cli\r\n          id={todo.id}\r\n          onClick={toggleCompleted}\r\n          className={todo.completed ? \"Todo-task completed\" : \"Todo-task\"}\r\n        >\r\n          {todo.task}\r\n        \u003c/li>\r\n        \u003cdiv className=\"Todo-buttons\">\r\n          \u003cbutton onClick={toggleFrom}>\r\n            \u003ci className=\"fas fa-pen\" />\r\n          \u003c/button>\r\n          \u003cbutton onClick={handleClick}>\r\n            \u003ci id={todo.id} className=\"fas fa-trash\" />\r\n          \u003c/button>\r\n        \u003c/div>\r\n      \u003c/div>\r\n    );\r\n  }\r\n  return result;\r\n}\r\n\r\nexport default Todo;\r\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": ["/src/Todo.css:", "/node_modules/react/index.js:", "/node_modules/react-dom/index.js:", "/node_modules/@babel/runtime/helpers/interopRequireDefault.js:", "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js:"],
              "initiators": ["/src/TodoList.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/Todo.js",
                "compiledCode": "\"use strict\";\n\nvar _interopRequireDefault = require(\"@babel/runtime/helpers/interopRequireDefault\");\nObject.defineProperty(exports, \"__esModule\", {\n  value: true\n});\nexports.default = void 0;\nvar _react = _interopRequireWildcard(require(\"react\"));\nvar _reactDom = _interopRequireDefault(require(\"react-dom\"));\nrequire(\"./Todo.css\");\nvar _jsxFileName = \"/src/Todo.js\";\nfunction _getRequireWildcardCache(nodeInterop) { if (typeof WeakMap !== \"function\") return null; var cacheBabelInterop = new WeakMap(); var cacheNodeInterop = new WeakMap(); return (_getRequireWildcardCache = function (nodeInterop) { return nodeInterop ? cacheNodeInterop : cacheBabelInterop; })(nodeInterop); }\nfunction _interopRequireWildcard(obj, nodeInterop) { if (!nodeInterop && obj && obj.__esModule) { return obj; } if (obj === null || typeof obj !== \"object\" && typeof obj !== \"function\") { return { default: obj }; } var cache = _getRequireWildcardCache(nodeInterop); if (cache && cache.has(obj)) { return cache.get(obj); } var newObj = {}; var hasPropertyDescriptor = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var key in obj) { if (key !== \"default\" && Object.prototype.hasOwnProperty.call(obj, key)) { var desc = hasPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : null; if (desc && (desc.get || desc.set)) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } newObj.default = obj; if (cache) { cache.set(obj, newObj); } return newObj; }\nfunction Todo(_ref) {\n  let {\n    todo,\n    remove,\n    update,\n    toggleComplete\n  } = _ref;\n  const [isEditing, setIsEditing] = (0, _react.useState)(false);\n  const [task, setTask] = (0, _react.useState)(todo.task);\n  const handleClick = evt => {\n    remove(evt.target.id);\n  };\n  const toggleFrom = () => {\n    setIsEditing(!isEditing);\n  };\n  const handleUpdate = evt => {\n    evt.preventDefault();\n    update(todo.id, task);\n    toggleFrom();\n  };\n  const handleChange = evt => {\n    setTask(evt.target.value);\n  };\n  const toggleCompleted = evt => {\n    toggleComplete(evt.target.id);\n  };\n  let result;\n  if (isEditing) {\n    result = /*#__PURE__*/_react.default.createElement(\"div\", {\n      className: \"Todo\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 30,\n        columnNumber: 7\n      }\n    }, /*#__PURE__*/_react.default.createElement(\"form\", {\n      className: \"Todo-edit-form\",\n      onSubmit: handleUpdate,\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 31,\n        columnNumber: 9\n      }\n    }, /*#__PURE__*/_react.default.createElement(\"input\", {\n      onChange: handleChange,\n      value: task,\n      type: \"text\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 32,\n        columnNumber: 11\n      }\n    }), /*#__PURE__*/_react.default.createElement(\"button\", {\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 33,\n        columnNumber: 11\n      }\n    }, \"Save\")));\n  } else {\n    result = /*#__PURE__*/_react.default.createElement(\"div\", {\n      className: \"Todo\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 39,\n        columnNumber: 7\n      }\n    }, /*#__PURE__*/_react.default.createElement(\"li\", {\n      id: todo.id,\n      onClick: toggleCompleted,\n      className: todo.completed ? \"Todo-task completed\" : \"Todo-task\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 40,\n        columnNumber: 9\n      }\n    }, todo.task), /*#__PURE__*/_react.default.createElement(\"div\", {\n      className: \"Todo-buttons\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 47,\n        columnNumber: 9\n      }\n    }, /*#__PURE__*/_react.default.createElement(\"button\", {\n      onClick: toggleFrom,\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 48,\n        columnNumber: 11\n      }\n    }, /*#__PURE__*/_react.default.createElement(\"i\", {\n      className: \"fas fa-pen\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 49,\n        columnNumber: 13\n      }\n    })), /*#__PURE__*/_react.default.createElement(\"button\", {\n      onClick: handleClick,\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 51,\n        columnNumber: 11\n      }\n    }, /*#__PURE__*/_react.default.createElement(\"i\", {\n      id: todo.id,\n      className: \"fas fa-trash\",\n      __source: {\n        fileName: _jsxFileName,\n        lineNumber: 52,\n        columnNumber: 13\n      }\n    }))));\n  }\n  return result;\n}\nvar _default = Todo;\nexports.default = _default;\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJuYW1lcyI6WyJfcmVhY3QiLCJfaW50ZXJvcFJlcXVpcmVXaWxkY2FyZCIsInJlcXVpcmUiLCJfcmVhY3REb20iLCJfaW50ZXJvcFJlcXVpcmVEZWZhdWx0IiwiX2pzeEZpbGVOYW1lIiwiX2dldFJlcXVpcmVXaWxkY2FyZENhY2hlIiwibm9kZUludGVyb3AiLCJXZWFrTWFwIiwiY2FjaGVCYWJlbEludGVyb3AiLCJjYWNoZU5vZGVJbnRlcm9wIiwib2JqIiwiX19lc01vZHVsZSIsImRlZmF1bHQiLCJjYWNoZSIsImhhcyIsImdldCIsIm5ld09iaiIsImhhc1Byb3BlcnR5RGVzY3JpcHRvciIsIk9iamVjdCIsImRlZmluZVByb3BlcnR5IiwiZ2V0T3duUHJvcGVydHlEZXNjcmlwdG9yIiwia2V5IiwicHJvdG90eXBlIiwiaGFzT3duUHJvcGVydHkiLCJjYWxsIiwiZGVzYyIsInNldCIsIlRvZG8iLCJfcmVmIiwidG9kbyIsInJlbW92ZSIsInVwZGF0ZSIsInRvZ2dsZUNvbXBsZXRlIiwiaXNFZGl0aW5nIiwic2V0SXNFZGl0aW5nIiwidXNlU3RhdGUiLCJ0YXNrIiwic2V0VGFzayIsImhhbmRsZUNsaWNrIiwiZXZ0IiwidGFyZ2V0IiwiaWQiLCJ0b2dnbGVGcm9tIiwiaGFuZGxlVXBkYXRlIiwicHJldmVudERlZmF1bHQiLCJoYW5kbGVDaGFuZ2UiLCJ2YWx1ZSIsInRvZ2dsZUNvbXBsZXRlZCIsInJlc3VsdCIsImNyZWF0ZUVsZW1lbnQiLCJjbGFzc05hbWUiLCJfX3NvdXJjZSIsImZpbGVOYW1lIiwibGluZU51bWJlciIsImNvbHVtbk51bWJlciIsIm9uU3VibWl0Iiwib25DaGFuZ2UiLCJ0eXBlIiwib25DbGljayIsImNvbXBsZXRlZCIsIl9kZWZhdWx0IiwiZXhwb3J0cyJdLCJzb3VyY2VzIjpbIi9zcmMvVG9kby5qcyJdLCJzb3VyY2VzQ29udGVudCI6WyJpbXBvcnQgUmVhY3QsIHsgdXNlU3RhdGUgfSBmcm9tIFwicmVhY3RcIjtcclxuaW1wb3J0IFJlYWN0RE9NIGZyb20gXCJyZWFjdC1kb21cIjtcclxuaW1wb3J0IFwiLi9Ub2RvLmNzc1wiO1xyXG5cclxuZnVuY3Rpb24gVG9kbyh7IHRvZG8sIHJlbW92ZSwgdXBkYXRlLCB0b2dnbGVDb21wbGV0ZSB9KSB7XHJcbiAgY29uc3QgW2lzRWRpdGluZywgc2V0SXNFZGl0aW5nXSA9IHVzZVN0YXRlKGZhbHNlKTtcclxuICBjb25zdCBbdGFzaywgc2V0VGFza10gPSB1c2VTdGF0ZSh0b2RvLnRhc2spO1xyXG5cclxuICBjb25zdCBoYW5kbGVDbGljayA9IGV2dCA9PiB7XHJcbiAgICByZW1vdmUoZXZ0LnRhcmdldC5pZCk7XHJcbiAgfTtcclxuICBjb25zdCB0b2dnbGVGcm9tID0gKCkgPT4ge1xyXG4gICAgc2V0SXNFZGl0aW5nKCFpc0VkaXRpbmcpO1xyXG4gIH07XHJcbiAgY29uc3QgaGFuZGxlVXBkYXRlID0gZXZ0ID0+IHtcclxuICAgIGV2dC5wcmV2ZW50RGVmYXVsdCgpO1xyXG4gICAgdXBkYXRlKHRvZG8uaWQsIHRhc2spO1xyXG4gICAgdG9nZ2xlRnJvbSgpO1xyXG4gIH07XHJcbiAgY29uc3QgaGFuZGxlQ2hhbmdlID0gZXZ0ID0+IHtcclxuICAgIHNldFRhc2soZXZ0LnRhcmdldC52YWx1ZSk7XHJcbiAgfTtcclxuICBjb25zdCB0b2dnbGVDb21wbGV0ZWQgPSBldnQgPT4ge1xyXG4gICAgdG9nZ2xlQ29tcGxldGUoZXZ0LnRhcmdldC5pZCk7XHJcbiAgfTtcclxuXHJcbiAgbGV0IHJlc3VsdDtcclxuICBpZiAoaXNFZGl0aW5nKSB7XHJcbiAgICByZXN1bHQgPSAoXHJcbiAgICAgIDxkaXYgY2xhc3NOYW1lPVwiVG9kb1wiPlxyXG4gICAgICAgIDxmb3JtIGNsYXNzTmFtZT1cIlRvZG8tZWRpdC1mb3JtXCIgb25TdWJtaXQ9e2hhbmRsZVVwZGF0ZX0+XHJcbiAgICAgICAgICA8aW5wdXQgb25DaGFuZ2U9e2hhbmRsZUNoYW5nZX0gdmFsdWU9e3Rhc2t9IHR5cGU9XCJ0ZXh0XCIgLz5cclxuICAgICAgICAgIDxidXR0b24+U2F2ZTwvYnV0dG9uPlxyXG4gICAgICAgIDwvZm9ybT5cclxuICAgICAgPC9kaXY+XHJcbiAgICApO1xyXG4gIH0gZWxzZSB7XHJcbiAgICByZXN1bHQgPSAoXHJcbiAgICAgIDxkaXYgY2xhc3NOYW1lPVwiVG9kb1wiPlxyXG4gICAgICAgIDxsaVxyXG4gICAgICAgICAgaWQ9e3RvZG8uaWR9XHJcbiAgICAgICAgICBvbkNsaWNrPXt0b2dnbGVDb21wbGV0ZWR9XHJcbiAgICAgICAgICBjbGFzc05hbWU9e3RvZG8uY29tcGxldGVkID8gXCJUb2RvLXRhc2sgY29tcGxldGVkXCIgOiBcIlRvZG8tdGFza1wifVxyXG4gICAgICAgID5cclxuICAgICAgICAgIHt0b2RvLnRhc2t9XHJcbiAgICAgICAgPC9saT5cclxuICAgICAgICA8ZGl2IGNsYXNzTmFtZT1cIlRvZG8tYnV0dG9uc1wiPlxyXG4gICAgICAgICAgPGJ1dHRvbiBvbkNsaWNrPXt0b2dnbGVGcm9tfT5cclxuICAgICAgICAgICAgPGkgY2xhc3NOYW1lPVwiZmFzIGZhLXBlblwiIC8+XHJcbiAgICAgICAgICA8L2J1dHRvbj5cclxuICAgICAgICAgIDxidXR0b24gb25DbGljaz17aGFuZGxlQ2xpY2t9PlxyXG4gICAgICAgICAgICA8aSBpZD17dG9kby5pZH0gY2xhc3NOYW1lPVwiZmFzIGZhLXRyYXNoXCIgLz5cclxuICAgICAgICAgIDwvYnV0dG9uPlxyXG4gICAgICAgIDwvZGl2PlxyXG4gICAgICA8L2Rpdj5cclxuICAgICk7XHJcbiAgfVxyXG4gIHJldHVybiByZXN1bHQ7XHJcbn1cclxuXHJcbmV4cG9ydCBkZWZhdWx0IFRvZG87XHJcbiJdLCJtYXBwaW5ncyI6Ijs7Ozs7OztBQUFBLElBQUFBLE1BQUEsR0FBQUMsdUJBQUEsQ0FBQUMsT0FBQTtBQUNBLElBQUFDLFNBQUEsR0FBQUMsc0JBQUEsQ0FBQUYsT0FBQTtBQUNBQSxPQUFBO0FBQW9CLElBQUFHLFlBQUE7QUFBQSxTQUFBQyx5QkFBQUMsV0FBQSxlQUFBQyxP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",
                "sourceEqualsCompiled": false
              }
            },
            "/src/TodoList.css:": {
              "query": "",
              "module": {
                "path": "/src/TodoList.css",
                "code": ".TodoList {\r\n  margin: 4rem auto;\r\n  padding: 2rem 3rem 3rem;\r\n  max-width: 500px;\r\n  background: #ff6666;\r\n  color: #fff;\r\n  box-shadow: -20px -20px 0px 0px rgba(100, 100, 100, 0.1);\r\n}\r\n\r\n.TodoList ul {\r\n  margin-top: 2.6rem;\r\n  list-style: none;\r\n}\r\n\r\n.TodoList h1 {\r\n  font-weight: normal;\r\n  font-size: 2.6rem;\r\n  letter-spacing: 0.05em;\r\n  border-bottom: 1px solid rgba(255, 255, 255, 0.3);\r\n}\r\n\r\n.TodoList h1 span {\r\n  display: block;\r\n  font-size: 0.8rem;\r\n  margin-bottom: 0.7rem;\r\n  margin-left: 3px;\r\n  margin-top: 0.2rem;\r\n}\r\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": [],
              "initiators": ["/src/TodoList.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/TodoList.css",
                "compiledCode": "\nfunction createStyleNode(id, content) {\n  var styleNode =\n    document.getElementById(id) || document.createElement('style');\n\n  styleNode.setAttribute('id', id);\n  styleNode.type = 'text/css';\n  if (styleNode.styleSheet) {\n    styleNode.styleSheet.cssText = content;\n  } else {\n    styleNode.innerHTML = '';\n    styleNode.appendChild(document.createTextNode(content));\n  }\n  document.head.appendChild(styleNode);\n}\n\ncreateStyleNode(\n  \"/src/TodoList.css:-css\",\n  \".TodoList {\\r\\n  margin: 4rem auto;\\r\\n  padding: 2rem 3rem 3rem;\\r\\n  max-width: 500px;\\r\\n  background: #ff6666;\\r\\n  color: #fff;\\r\\n  box-shadow: -20px -20px 0px 0px rgba(100, 100, 100, 0.1);\\r\\n}\\r\\n\\r\\n.TodoList ul {\\r\\n  margin-top: 2.6rem;\\r\\n  list-style: none;\\r\\n}\\r\\n\\r\\n.TodoList h1 {\\r\\n  font-weight: normal;\\r\\n  font-size: 2.6rem;\\r\\n  letter-spacing: 0.05em;\\r\\n  border-bottom: 1px solid rgba(255, 255, 255, 0.3);\\r\\n}\\r\\n\\r\\n.TodoList h1 span {\\r\\n  display: block;\\r\\n  font-size: 0.8rem;\\r\\n  margin-bottom: 0.7rem;\\r\\n  margin-left: 3px;\\r\\n  margin-top: 0.2rem;\\r\\n}\\r\\n\"\n);\n\n\n",
                "sourceEqualsCompiled": false
              }
            },
            "/src/TodoList.js:": {
              "query": "",
              "module": {
                "path": "/src/TodoList.js",
                "code": "import React, { useState } from \"react\";\r\nimport ReactDOM from \"react-dom\";\r\nimport Todo from \"./Todo\";\r\nimport NewTodoForm from \"./NewTodoForm\";\r\nimport uuid from \"uuid\";\r\nimport \"./TodoList.css\";\r\n\r\nfunction TodoList() {\r\n  const [todos, setTodos] = useState([\r\n    { id: uuid(), task: \"task 1\", completed: false },\r\n    { id: uuid(), task: \"task 2\", completed: true }\r\n  ]);\r\n\r\n  const create = newTodo => {\r\n    console.log(newTodo);\r\n    setTodos([...todos, newTodo]);\r\n  };\r\n\r\n  const remove = id => {\r\n    setTodos(todos.filter(todo => todo.id !== id));\r\n  };\r\n\r\n  const update = (id, updtedTask) => {\r\n    const updatedTodos = todos.map(todo => {\r\n      if (todo.id === id) {\r\n        return { ...todo, task: updtedTask };\r\n      }\r\n      return todo;\r\n    });\r\n    setTodos(updatedTodos);\r\n  };\r\n\r\n  const toggleComplete = id => {\r\n    const updatedTodos = todos.map(todo => {\r\n      if (todo.id === id) {\r\n        return { ...todo, completed: !todo.completed };\r\n      }\r\n      return todo;\r\n    });\r\n    setTodos(updatedTodos);\r\n  };\r\n\r\n  const todosList = todos.map(todo => (\r\n    \u003cTodo\r\n      toggleComplete={toggleComplete}\r\n      update={update}\r\n      remove={remove}\r\n      key={todo.id}\r\n      todo={todo}\r\n    />\r\n  ));\r\n\r\n  return (\r\n    \u003cdiv className=\"TodoList\">\r\n      \u003ch1>\r\n        Todo List \u003cspan>A simple React Todo List App\u003c/span>\r\n      \u003c/h1>\r\n      \u003cul>{todosList}\u003c/ul>\r\n      \u003cNewTodoForm createTodo={create} />\r\n    \u003c/div>\r\n  );\r\n}\r\n\r\nexport default TodoList;\r\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": ["/src/TodoList.css:", "/node_modules/react/index.js:", "/src/Todo.js:", "/src/NewTodoForm.js:", "/node_modules/react-dom/index.js:", "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js:", "/node_modules/@babel/runtime/helpers/interopRequireDefault.js:", "/node_modules/uuid/index.js:"],
              "initiators": ["/src/index.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/TodoList.js",
                "compiledCode": "\"use strict\";\n\nvar _interopRequireDefault = require(\"@babel/runtime/helpers/interopRequireDefault\");\nObject.defineProperty(exports, \"__esModule\", {\n  value: true\n});\nexports.default = void 0;\nvar _react = _interopRequireWildcard(require(\"react\"));\nvar _reactDom = _interopRequireDefault(require(\"react-dom\"));\nvar _Todo = _interopRequireDefault(require(\"./Todo\"));\nvar _NewTodoForm = _interopRequireDefault(require(\"./NewTodoForm\"));\nvar _uuid = _interopRequireDefault(require(\"uuid\"));\nrequire(\"./TodoList.css\");\nvar _jsxFileName = \"/src/TodoList.js\";\nfunction _getRequireWildcardCache(nodeInterop) { if (typeof WeakMap !== \"function\") return null; var cacheBabelInterop = new WeakMap(); var cacheNodeInterop = new WeakMap(); return (_getRequireWildcardCache = function (nodeInterop) { return nodeInterop ? cacheNodeInterop : cacheBabelInterop; })(nodeInterop); }\nfunction _interopRequireWildcard(obj, nodeInterop) { if (!nodeInterop && obj && obj.__esModule) { return obj; } if (obj === null || typeof obj !== \"object\" && typeof obj !== \"function\") { return { default: obj }; } var cache = _getRequireWildcardCache(nodeInterop); if (cache && cache.has(obj)) { return cache.get(obj); } var newObj = {}; var hasPropertyDescriptor = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var key in obj) { if (key !== \"default\" && Object.prototype.hasOwnProperty.call(obj, key)) { var desc = hasPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : null; if (desc && (desc.get || desc.set)) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } newObj.default = obj; if (cache) { cache.set(obj, newObj); } return newObj; }\nfunction TodoList() {\n  const [todos, setTodos] = (0, _react.useState)([{\n    id: (0, _uuid.default)(),\n    task: \"task 1\",\n    completed: false\n  }, {\n    id: (0, _uuid.default)(),\n    task: \"task 2\",\n    completed: true\n  }]);\n  const create = newTodo => {\n    console.log(newTodo);\n    setTodos([...todos, newTodo]);\n  };\n  const remove = id => {\n    setTodos(todos.filter(todo => todo.id !== id));\n  };\n  const update = (id, updtedTask) => {\n    const updatedTodos = todos.map(todo => {\n      if (todo.id === id) {\n        return {\n          ...todo,\n          task: updtedTask\n        };\n      }\n      return todo;\n    });\n    setTodos(updatedTodos);\n  };\n  const toggleComplete = id => {\n    const updatedTodos = todos.map(todo => {\n      if (todo.id === id) {\n        return {\n          ...todo,\n          completed: !todo.completed\n        };\n      }\n      return todo;\n    });\n    setTodos(updatedTodos);\n  };\n  const todosList = todos.map(todo => /*#__PURE__*/_react.default.createElement(_Todo.default, {\n    toggleComplete: toggleComplete,\n    update: update,\n    remove: remove,\n    key: todo.id,\n    todo: todo,\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 44,\n      columnNumber: 5\n    }\n  }));\n  return /*#__PURE__*/_react.default.createElement(\"div\", {\n    className: \"TodoList\",\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 54,\n      columnNumber: 5\n    }\n  }, /*#__PURE__*/_react.default.createElement(\"h1\", {\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 55,\n      columnNumber: 7\n    }\n  }, \"Todo List \", /*#__PURE__*/_react.default.createElement(\"span\", {\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 56,\n      columnNumber: 19\n    }\n  }, \"A simple React Todo List App\")), /*#__PURE__*/_react.default.createElement(\"ul\", {\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 58,\n      columnNumber: 7\n    }\n  }, todosList), /*#__PURE__*/_react.default.createElement(_NewTodoForm.default, {\n    createTodo: create,\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 59,\n      columnNumber: 7\n    }\n  }));\n}\nvar _default = TodoList;\nexports.default = _default;\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJuYW1lcyI6WyJfcmVhY3QiLCJfaW50ZXJvcFJlcXVpcmVXaWxkY2FyZCIsInJlcXVpcmUiLCJfcmVhY3REb20iLCJfaW50ZXJvcFJlcXVpcmVEZWZhdWx0IiwiX1RvZG8iLCJfTmV3VG9kb0Zvcm0iLCJfdXVpZCIsIl9qc3hGaWxlTmFtZSIsIl9nZXRSZXF1aXJlV2lsZGNhcmRDYWNoZSIsIm5vZGVJbnRlcm9wIiwiV2Vha01hcCIsImNhY2hlQmFiZWxJbnRlcm9wIiwiY2FjaGVOb2RlSW50ZXJvcCIsIm9iaiIsIl9fZXNNb2R1bGUiLCJkZWZhdWx0IiwiY2FjaGUiLCJoYXMiLCJnZXQiLCJuZXdPYmoiLCJoYXNQcm9wZXJ0eURlc2NyaXB0b3IiLCJPYmplY3QiLCJkZWZpbmVQcm9wZXJ0eSIsImdldE93blByb3BlcnR5RGVzY3JpcHRvciIsImtleSIsInByb3RvdHlwZSIsImhhc093blByb3BlcnR5IiwiY2FsbCIsImRlc2MiLCJzZXQiLCJUb2RvTGlzdCIsInRvZG9zIiwic2V0VG9kb3MiLCJ1c2VTdGF0ZSIsImlkIiwidXVpZCIsInRhc2siLCJjb21wbGV0ZWQiLCJjcmVhdGUiLCJuZXdUb2RvIiwiY29uc29sZSIsImxvZyIsInJlbW92ZSIsImZpbHRlciIsInRvZG8iLCJ1cGRhdGUiLCJ1cGR0ZWRUYXNrIiwidXBkYXRlZFRvZG9zIiwibWFwIiwidG9nZ2xlQ29tcGxldGUiLCJ0b2Rvc0xpc3QiLCJjcmVhdGVFbGVtZW50IiwiX19zb3VyY2UiLCJmaWxlTmFtZSIsImxpbmVOdW1iZXIiLCJjb2x1bW5OdW1iZXIiLCJjbGFzc05hbWUiLCJjcmVhdGVUb2RvIiwiX2RlZmF1bHQiLCJleHBvcnRzIl0sInNvdXJjZXMiOlsiL3NyYy9Ub2RvTGlzdC5qcyJdLCJzb3VyY2VzQ29udGVudCI6WyJpbXBvcnQgUmVhY3QsIHsgdXNlU3RhdGUgfSBmcm9tIFwicmVhY3RcIjtcclxuaW1wb3J0IFJlYWN0RE9NIGZyb20gXCJyZWFjdC1kb21cIjtcclxuaW1wb3J0IFRvZG8gZnJvbSBcIi4vVG9kb1wiO1xyXG5pbXBvcnQgTmV3VG9kb0Zvcm0gZnJvbSBcIi4vTmV3VG9kb0Zvcm1cIjtcclxuaW1wb3J0IHV1aWQgZnJvbSBcInV1aWRcIjtcclxuaW1wb3J0IFwiLi9Ub2RvTGlzdC5jc3NcIjtcclxuXHJcbmZ1bmN0aW9uIFRvZG9MaXN0KCkge1xyXG4gIGNvbnN0IFt0b2Rvcywgc2V0VG9kb3NdID0gdXNlU3RhdGUoW1xyXG4gICAgeyBpZDogdXVpZCgpLCB0YXNrOiBcInRhc2sgMVwiLCBjb21wbGV0ZWQ6IGZhbHNlIH0sXHJcbiAgICB7IGlkOiB1dWlkKCksIHRhc2s6IFwidGFzayAyXCIsIGNvbXBsZXRlZDogdHJ1ZSB9XHJcbiAgXSk7XHJcblxyXG4gIGNvbnN0IGNyZWF0ZSA9IG5ld1RvZG8gPT4ge1xyXG4gICAgY29uc29sZS5sb2cobmV3VG9kbyk7XHJcbiAgICBzZXRUb2RvcyhbLi4udG9kb3MsIG5ld1RvZG9dKTtcclxuICB9O1xyXG5cclxuICBjb25zdCByZW1vdmUgPSBpZCA9PiB7XHJcbiAgICBzZXRUb2Rvcyh0b2Rvcy5maWx0ZXIodG9kbyA9PiB0b2RvLmlkICE9PSBpZCkpO1xyXG4gIH07XHJcblxyXG4gIGNvbnN0IHVwZGF0ZSA9IChpZCwgdXBkdGVkVGFzaykgPT4ge1xyXG4gICAgY29uc3QgdXBkYXRlZFRvZG9zID0gdG9kb3MubWFwKHRvZG8gPT4ge1xyXG4gICAgICBpZiAodG9kby5pZCA9PT0gaWQpIHtcclxuICAgICAgICByZXR1cm4geyAuLi50b2RvLCB0YXNrOiB1cGR0ZWRUYXNrIH07XHJcbiAgICAgIH1cclxuICAgICAgcmV0dXJuIHRvZG87XHJcbiAgICB9KTtcclxuICAgIHNldFRvZG9zKHVwZGF0ZWRUb2Rvcyk7XHJcbiAgfTtcclxuXHJcbiAgY29uc3QgdG9nZ2xlQ29tcGxldGUgPSBpZCA9PiB7XHJcbiAgICBjb25zdCB1cGRhdGVkVG9kb3MgPSB0b2Rvcy5tYXAodG9kbyA9PiB7XHJcbiAgICAgIGlmICh0b2RvLmlkID09PSBpZCkge1xyXG4gICAgICAgIHJldHVybiB7IC4uLnRvZG8sIGNvbXBsZXRlZDogIXRvZG8uY29tcGxldGVkIH07XHJcbiAgICAgIH1cclxuICAgICAgcmV0dXJuIHRvZG87XHJcbiAgICB9KTtcclxuICAgIHNldFRvZG9zKHVwZGF0ZWRUb2Rvcyk7XHJcbiAgfTtcclxuXHJcbiAgY29uc3QgdG9kb3NMaXN0ID0gdG9kb3MubWFwKHRvZG8gPT4gKFxyXG4gICAgPFRvZG9cclxuICAgICAgdG9nZ2xlQ29tcGxldGU9e3RvZ2dsZUNvbXBsZXRlfVxyXG4gICAgICB1cGRhdGU9e3VwZGF0ZX1cclxuICAgICAgcmVtb3ZlPXtyZW1vdmV9XHJcbiAgICAgIGtleT17dG9kby5pZH1cclxuICAgICAgdG9kbz17dG9kb31cclxuICAgIC8+XHJcbiAgKSk7XHJcblxyXG4gIHJldHVybiAoXHJcbiAgICA8ZGl2IGNsYXNzTmFtZT1cIlRvZG9MaXN0XCI+XHJcbiAgICAgIDxoMT5cclxuICAgICAgICBUb2RvIExpc3QgPHNwYW4+QSBzaW1wbGUgUmVhY3QgVG9kbyBMaXN0IEFwcDwvc3Bhbj5cclxuICAgICAgPC9oMT5cclxuICAgICAgPHVsPnt0b2Rvc0xpc3R9PC91bD5cclxuICAgICAgPE5ld1RvZG9Gb3JtIGNyZWF0ZVRvZG89e2NyZWF0ZX0gLz5cclxuICAgIDwvZGl2PlxyXG4gICk7XHJcbn1cclxuXHJcbmV4cG9ydCBkZWZhdWx0IFRvZG9MaXN0O1xyXG4iXSwibWFwcGluZ3MiOiI7Ozs7Ozs7QUFBQSxJQUFBQSxNQUFBLEdBQUFDLHVCQUFBLENBQUFDLE9BQUE7QUFDQSxJQUFBQyxTQUFBLEdBQUFDLHNCQUFBLENBQUFGLE9BQUE7QUFDQSxJQUFBRyxLQUFBLEdBQUFELHNCQUFBLENBQUFGLE9BQUE7QUFDQSxJQUFBSSxZQUFBLEdBQUFGLHNCQUFBLENBQUFGLE9BQUE7QUFDQSxJQUFBSyxLQUFBLEdBQUFILHNCQUFBLENBQUFGLE9BQUE7QUFDQUEsT0FBQTtBQUF3QixJQUFBTSxZQUFBO0FBQUEsU0FBQUMseUJBQUFDLFdB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",
                "sourceEqualsCompiled": false
              }
            },
            "/src/NewTodoForm.js:": {
              "query": "",
              "module": {
                "path": "/src/NewTodoForm.js",
                "code": "import React, { useState, useReducer } from \"react\";\r\nimport ReactDOM from \"react-dom\";\r\nimport uuid from \"uuid\";\r\nimport \"./newTodoForm.css\";\r\n\r\nfunction NewTodoForm({ task, createTodo }) {\r\n  const [userInput, setUserInput] = useReducer(\r\n    (state, newState) => ({ ...state, ...newState }),\r\n    {\r\n      task: \"\"\r\n    }\r\n  );\r\n\r\n  const handleChange = evt => {\r\n    setUserInput({ [evt.target.name]: evt.target.value });\r\n  };\r\n\r\n  const handleSubmit = evt => {\r\n    evt.preventDefault();\r\n    const newTodo = { id: uuid(), task: userInput.task, completed: false };\r\n    createTodo(newTodo);\r\n    setUserInput({ task: \"\" });\r\n  };\r\n\r\n  return (\r\n    \u003cform className=\"NewTodoForm\" onSubmit={handleSubmit}>\r\n      \u003clabel htmlFor=\"task\">New todo\u003c/label>\r\n      \u003cinput\r\n        value={userInput.task}\r\n        onChange={handleChange}\r\n        id=\"task\"\r\n        type=\"text\"\r\n        name=\"task\"\r\n        placeholder=\"New Todo\"\r\n      />\r\n      \u003cbutton>Add Todo\u003c/button>\r\n    \u003c/form>\r\n  );\r\n}\r\n\r\nexport default NewTodoForm;\r\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": ["/node_modules/react/index.js:", "/node_modules/react-dom/index.js:", "/node_modules/@babel/runtime/helpers/interopRequireDefault.js:", "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js:", "/src/newTodoForm.css:", "/node_modules/uuid/index.js:"],
              "initiators": ["/src/TodoList.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/NewTodoForm.js",
                "compiledCode": "\"use strict\";\n\nvar _interopRequireDefault = require(\"@babel/runtime/helpers/interopRequireDefault\");\nObject.defineProperty(exports, \"__esModule\", {\n  value: true\n});\nexports.default = void 0;\nvar _react = _interopRequireWildcard(require(\"react\"));\nvar _reactDom = _interopRequireDefault(require(\"react-dom\"));\nvar _uuid = _interopRequireDefault(require(\"uuid\"));\nrequire(\"./newTodoForm.css\");\nvar _jsxFileName = \"/src/NewTodoForm.js\";\nfunction _getRequireWildcardCache(nodeInterop) { if (typeof WeakMap !== \"function\") return null; var cacheBabelInterop = new WeakMap(); var cacheNodeInterop = new WeakMap(); return (_getRequireWildcardCache = function (nodeInterop) { return nodeInterop ? cacheNodeInterop : cacheBabelInterop; })(nodeInterop); }\nfunction _interopRequireWildcard(obj, nodeInterop) { if (!nodeInterop && obj && obj.__esModule) { return obj; } if (obj === null || typeof obj !== \"object\" && typeof obj !== \"function\") { return { default: obj }; } var cache = _getRequireWildcardCache(nodeInterop); if (cache && cache.has(obj)) { return cache.get(obj); } var newObj = {}; var hasPropertyDescriptor = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var key in obj) { if (key !== \"default\" && Object.prototype.hasOwnProperty.call(obj, key)) { var desc = hasPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : null; if (desc && (desc.get || desc.set)) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } newObj.default = obj; if (cache) { cache.set(obj, newObj); } return newObj; }\nfunction NewTodoForm(_ref) {\n  let {\n    task,\n    createTodo\n  } = _ref;\n  const [userInput, setUserInput] = (0, _react.useReducer)((state, newState) => ({\n    ...state,\n    ...newState\n  }), {\n    task: \"\"\n  });\n  const handleChange = evt => {\n    setUserInput({\n      [evt.target.name]: evt.target.value\n    });\n  };\n  const handleSubmit = evt => {\n    evt.preventDefault();\n    const newTodo = {\n      id: (0, _uuid.default)(),\n      task: userInput.task,\n      completed: false\n    };\n    createTodo(newTodo);\n    setUserInput({\n      task: \"\"\n    });\n  };\n  return /*#__PURE__*/_react.default.createElement(\"form\", {\n    className: \"NewTodoForm\",\n    onSubmit: handleSubmit,\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 26,\n      columnNumber: 5\n    }\n  }, /*#__PURE__*/_react.default.createElement(\"label\", {\n    htmlFor: \"task\",\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 27,\n      columnNumber: 7\n    }\n  }, \"New todo\"), /*#__PURE__*/_react.default.createElement(\"input\", {\n    value: userInput.task,\n    onChange: handleChange,\n    id: \"task\",\n    type: \"text\",\n    name: \"task\",\n    placeholder: \"New Todo\",\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 28,\n      columnNumber: 7\n    }\n  }), /*#__PURE__*/_react.default.createElement(\"button\", {\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 36,\n      columnNumber: 7\n    }\n  }, \"Add Todo\"));\n}\nvar _default = NewTodoForm;\nexports.default = _default;\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJuYW1lcyI6WyJfcmVhY3QiLCJfaW50ZXJvcFJlcXVpcmVXaWxkY2FyZCIsInJlcXVpcmUiLCJfcmVhY3REb20iLCJfaW50ZXJvcFJlcXVpcmVEZWZhdWx0IiwiX3V1aWQiLCJfanN4RmlsZU5hbWUiLCJfZ2V0UmVxdWlyZVdpbGRjYXJkQ2FjaGUiLCJub2RlSW50ZXJvcCIsIldlYWtNYXAiLCJjYWNoZUJhYmVsSW50ZXJvcCIsImNhY2hlTm9kZUludGVyb3AiLCJvYmoiLCJfX2VzTW9kdWxlIiwiZGVmYXVsdCIsImNhY2hlIiwiaGFzIiwiZ2V0IiwibmV3T2JqIiwiaGFzUHJvcGVydHlEZXNjcmlwdG9yIiwiT2JqZWN0IiwiZGVmaW5lUHJvcGVydHkiLCJnZXRPd25Qcm9wZXJ0eURlc2NyaXB0b3IiLCJrZXkiLCJwcm90b3R5cGUiLCJoYXNPd25Qcm9wZXJ0eSIsImNhbGwiLCJkZXNjIiwic2V0IiwiTmV3VG9kb0Zvcm0iLCJfcmVmIiwidGFzayIsImNyZWF0ZVRvZG8iLCJ1c2VySW5wdXQiLCJzZXRVc2VySW5wdXQiLCJ1c2VSZWR1Y2VyIiwic3RhdGUiLCJuZXdTdGF0ZSIsImhhbmRsZUNoYW5nZSIsImV2dCIsInRhcmdldCIsIm5hbWUiLCJ2YWx1ZSIsImhhbmRsZVN1Ym1pdCIsInByZXZlbnREZWZhdWx0IiwibmV3VG9kbyIsImlkIiwidXVpZCIsImNvbXBsZXRlZCIsImNyZWF0ZUVsZW1lbnQiLCJjbGFzc05hbWUiLCJvblN1Ym1pdCIsIl9fc291cmNlIiwiZmlsZU5hbWUiLCJsaW5lTnVtYmVyIiwiY29sdW1uTnVtYmVyIiwiaHRtbEZvciIsIm9uQ2hhbmdlIiwidHlwZSIsInBsYWNlaG9sZGVyIiwiX2RlZmF1bHQiLCJleHBvcnRzIl0sInNvdXJjZXMiOlsiL3NyYy9OZXdUb2RvRm9ybS5qcyJdLCJzb3VyY2VzQ29udGVudCI6WyJpbXBvcnQgUmVhY3QsIHsgdXNlU3RhdGUsIHVzZVJlZHVjZXIgfSBmcm9tIFwicmVhY3RcIjtcclxuaW1wb3J0IFJlYWN0RE9NIGZyb20gXCJyZWFjdC1kb21cIjtcclxuaW1wb3J0IHV1aWQgZnJvbSBcInV1aWRcIjtcclxuaW1wb3J0IFwiLi9uZXdUb2RvRm9ybS5jc3NcIjtcclxuXHJcbmZ1bmN0aW9uIE5ld1RvZG9Gb3JtKHsgdGFzaywgY3JlYXRlVG9kbyB9KSB7XHJcbiAgY29uc3QgW3VzZXJJbnB1dCwgc2V0VXNlcklucHV0XSA9IHVzZVJlZHVjZXIoXHJcbiAgICAoc3RhdGUsIG5ld1N0YXRlKSA9PiAoeyAuLi5zdGF0ZSwgLi4ubmV3U3RhdGUgfSksXHJcbiAgICB7XHJcbiAgICAgIHRhc2s6IFwiXCJcclxuICAgIH1cclxuICApO1xyXG5cclxuICBjb25zdCBoYW5kbGVDaGFuZ2UgPSBldnQgPT4ge1xyXG4gICAgc2V0VXNlcklucHV0KHsgW2V2dC50YXJnZXQubmFtZV06IGV2dC50YXJnZXQudmFsdWUgfSk7XHJcbiAgfTtcclxuXHJcbiAgY29uc3QgaGFuZGxlU3VibWl0ID0gZXZ0ID0+IHtcclxuICAgIGV2dC5wcmV2ZW50RGVmYXVsdCgpO1xyXG4gICAgY29uc3QgbmV3VG9kbyA9IHsgaWQ6IHV1aWQoKSwgdGFzazogdXNlcklucHV0LnRhc2ssIGNvbXBsZXRlZDogZmFsc2UgfTtcclxuICAgIGNyZWF0ZVRvZG8obmV3VG9kbyk7XHJcbiAgICBzZXRVc2VySW5wdXQoeyB0YXNrOiBcIlwiIH0pO1xyXG4gIH07XHJcblxyXG4gIHJldHVybiAoXHJcbiAgICA8Zm9ybSBjbGFzc05hbWU9XCJOZXdUb2RvRm9ybVwiIG9uU3VibWl0PXtoYW5kbGVTdWJtaXR9PlxyXG4gICAgICA8bGFiZWwgaHRtbEZvcj1cInRhc2tcIj5OZXcgdG9kbzwvbGFiZWw+XHJcbiAgICAgIDxpbnB1dFxyXG4gICAgICAgIHZhbHVlPXt1c2VySW5wdXQudGFza31cclxuICAgICAgICBvbkNoYW5nZT17aGFuZGxlQ2hhbmdlfVxyXG4gICAgICAgIGlkPVwidGFza1wiXHJcbiAgICAgICAgdHlwZT1cInRleHRcIlxyXG4gICAgICAgIG5hbWU9XCJ0YXNrXCJcclxuICAgICAgICBwbGFjZWhvbGRlcj1cIk5ldyBUb2RvXCJcclxuICAgICAgLz5cclxuICAgICAgPGJ1dHRvbj5BZGQgVG9kbzwvYnV0dG9uPlxyXG4gICAgPC9mb3JtPlxyXG4gICk7XHJcbn1cclxuXHJcbmV4cG9ydCBkZWZhdWx0IE5ld1RvZG9Gb3JtO1xyXG4iXSwibWFwcGluZ3MiOiI7Ozs7Ozs7QUFBQSxJQUFBQSxNQUFBLEdBQUFDLHVCQUFBLENBQUFDLE9BQUE7QUFDQSxJQUFBQyxTQUFBLEdBQUFDLHNCQUFBLENBQUFGLE9BQUE7QUFDQSxJQUFBRyxLQUFBLEdBQUFELHNCQUFBLENBQUFGLE9BQUE7QUFDQUEsT0FBQTtBQUEyQixJQUFBSSxZQUFBO0FBQUEsU0FBQUMseUJBQUFDLFdBQUEsZUFBQUMsT0FBQSxrQ0FBQUMsaUJBQUEsT0FBQUQsT0FBQSxRQUFBRSxnQkFBQSxPQUFBRixPQUFBLFlBQUFGLHdCQUFBLFlBQUFBLENBQUFDLFdBQUEsV0FBQUEsV0FBQSxHQUFBRyxnQkFBQSxHQUFBRCxpQkFBQSxLQUFBRixXQUFBO0FBQUEsU0FBQVAsd0JBQUFXLEdBQUEsRUFBQUosV0FBQSxTQUFBQSxXQUFBLElBQUFJLEdBQUEsSUFBQUEsR0FBQSxDQUFBQyxVQUFBLFdBQUFELEdBQUEsUUFBQUEsR0FBQSxvQkFBQUEsR0FBQSx3QkFBQUEsR0FBQSw0QkFBQUUsT0FBQSxFQUFBRixHQUFBLFVBQUFHLEtBQUEsR0FBQVIsd0JBQUEsQ0FBQUMsV0FBQSxPQUFBTyxLQUFBLElBQUFBLEtBQUEsQ0FBQUMsR0FBQSxDQUFBSixHQUFBLFlBQUFHLEtBQUEsQ0FBQUUsR0FBQSxDQUFBTCxHQUFBLFNBQUFNLE1BQUEsV0FBQUMscUJBQUEsR0FBQUMsTUFBQSxDQUFBQyxjQUFBLElBQUFELE1BQUEsQ0FBQUUsd0JBQUEsV0FBQUMsR0FBQSxJQUFBWCxHQUFBLFFBQUFXLEdBQUEsa0JBQUFILE1BQUEsQ0FBQUksU0FBQSxDQUFBQyxjQUFBLENBQUFDLElBQUEsQ0FBQWQsR0FBQSxFQUFBVyxH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",
                "sourceEqualsCompiled": false
              }
            },
            "/src/styles.css:": {
              "query": "",
              "module": {
                "path": "/src/styles.css",
                "code": "* {\n  margin: 0;\n  padding: 0;\n  box-sizing: border-box;\n}\nhtml,\nbody {\n  background: linear-gradient(90deg, #69b7eb, #b3dbd3, #f4d6db);\n  font-size: 1.1rem;\n  font-family: \"Quicksand\", sans-serif;\n  height: 100%;\n}\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": [],
              "initiators": ["/src/index.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/styles.css",
                "compiledCode": "\nfunction createStyleNode(id, content) {\n  var styleNode =\n    document.getElementById(id) || document.createElement('style');\n\n  styleNode.setAttribute('id', id);\n  styleNode.type = 'text/css';\n  if (styleNode.styleSheet) {\n    styleNode.styleSheet.cssText = content;\n  } else {\n    styleNode.innerHTML = '';\n    styleNode.appendChild(document.createTextNode(content));\n  }\n  document.head.appendChild(styleNode);\n}\n\ncreateStyleNode(\n  \"/src/styles.css:-css\",\n  \"* {\\n  margin: 0;\\n  padding: 0;\\n  box-sizing: border-box;\\n}\\nhtml,\\nbody {\\n  background: linear-gradient(90deg, #69b7eb, #b3dbd3, #f4d6db);\\n  font-size: 1.1rem;\\n  font-family: \\\"Quicksand\\\", sans-serif;\\n  height: 100%;\\n}\\n\"\n);\n\n\n",
                "sourceEqualsCompiled": false
              }
            },
            "/src/index.js:": {
              "query": "",
              "module": {
                "path": "/src/index.js",
                "code": "import React from \"react\";\nimport ReactDOM from \"react-dom\";\nimport TodoList from \"./TodoList.js\";\nimport \"./styles.css\";\n\n// Project for Udemy react bootcamp\n// https://www.udemy.com/course/modern-react-bootcamp/\n\nfunction App() {\n  return (\n    \u003cdiv className=\"App\">\n      \u003cTodoList />\n    \u003c/div>\n  );\n}\n\nconst rootElement = document.getElementById(\"root\");\nReactDOM.render(\u003cApp />, rootElement);\n",
                "isBinary": false
              },
              "isEntry": true,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": ["/src/TodoList.js:", "/src/styles.css:", "/node_modules/react/index.js:", "/node_modules/react-dom/index.js:", "/package.json:", "/node_modules/@babel/runtime/package.json:", "/node_modules/@babel/runtime/helpers/interopRequireDefault.js:", "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js:"],
              "initiators": [],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/index.js",
                "compiledCode": "\"use strict\";\n\nvar _interopRequireDefault = require(\"@babel/runtime/helpers/interopRequireDefault\");\nvar _react = _interopRequireDefault(require(\"react\"));\nvar _reactDom = _interopRequireDefault(require(\"react-dom\"));\nvar _TodoList = _interopRequireDefault(require(\"./TodoList.js\"));\nrequire(\"./styles.css\");\nvar _jsxFileName = \"/src/index.js\";\n// Project for Udemy react bootcamp\n// https://www.udemy.com/course/modern-react-bootcamp/\nfunction App() {\n  return /*#__PURE__*/_react.default.createElement(\"div\", {\n    className: \"App\",\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 11,\n      columnNumber: 5\n    }\n  }, /*#__PURE__*/_react.default.createElement(_TodoList.default, {\n    __source: {\n      fileName: _jsxFileName,\n      lineNumber: 12,\n      columnNumber: 7\n    }\n  }));\n}\nconst rootElement = document.getElementById(\"root\");\n_reactDom.default.render( /*#__PURE__*/_react.default.createElement(App, {\n  __source: {\n    fileName: _jsxFileName,\n    lineNumber: 18,\n    columnNumber: 17\n  }\n}), rootElement);\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJuYW1lcyI6WyJfcmVhY3QiLCJfaW50ZXJvcFJlcXVpcmVEZWZhdWx0IiwicmVxdWlyZSIsIl9yZWFjdERvbSIsIl9Ub2RvTGlzdCIsIl9qc3hGaWxlTmFtZSIsIkFwcCIsImRlZmF1bHQiLCJjcmVhdGVFbGVtZW50IiwiY2xhc3NOYW1lIiwiX19zb3VyY2UiLCJmaWxlTmFtZSIsImxpbmVOdW1iZXIiLCJjb2x1bW5OdW1iZXIiLCJyb290RWxlbWVudCIsImRvY3VtZW50IiwiZ2V0RWxlbWVudEJ5SWQiLCJSZWFjdERPTSIsInJlbmRlciJdLCJzb3VyY2VzIjpbIi9zcmMvaW5kZXguanMiXSwic291cmNlc0NvbnRlbnQiOlsiaW1wb3J0IFJlYWN0IGZyb20gXCJyZWFjdFwiO1xuaW1wb3J0IFJlYWN0RE9NIGZyb20gXCJyZWFjdC1kb21cIjtcbmltcG9ydCBUb2RvTGlzdCBmcm9tIFwiLi9Ub2RvTGlzdC5qc1wiO1xuaW1wb3J0IFwiLi9zdHlsZXMuY3NzXCI7XG5cbi8vIFByb2plY3QgZm9yIFVkZW15IHJlYWN0IGJvb3RjYW1wXG4vLyBodHRwczovL3d3dy51ZGVteS5jb20vY291cnNlL21vZGVybi1yZWFjdC1ib290Y2FtcC9cblxuZnVuY3Rpb24gQXBwKCkge1xuICByZXR1cm4gKFxuICAgIDxkaXYgY2xhc3NOYW1lPVwiQXBwXCI+XG4gICAgICA8VG9kb0xpc3QgLz5cbiAgICA8L2Rpdj5cbiAgKTtcbn1cblxuY29uc3Qgcm9vdEVsZW1lbnQgPSBkb2N1bWVudC5nZXRFbGVtZW50QnlJZChcInJvb3RcIik7XG5SZWFjdERPTS5yZW5kZXIoPEFwcCAvPiwgcm9vdEVsZW1lbnQpO1xuIl0sIm1hcHBpbmdzIjoiOzs7QUFBQSxJQUFBQSxNQUFBLEdBQUFDLHNCQUFBLENBQUFDLE9BQUE7QUFDQSxJQUFBQyxTQUFBLEdBQUFGLHNCQUFBLENBQUFDLE9BQUE7QUFDQSxJQUFBRSxTQUFBLEdBQUFILHNCQUFBLENBQUFDLE9BQUE7QUFDQUEsT0FBQTtBQUFzQixJQUFBRyxZQUFBO0FBRXRCO0FBQ0E7QUFFQSxTQUFTQyxHQUFHQSxDQUFBLEVBQUc7RUFDYixvQkFDRU4sTUFBQSxDQUFBTyxPQUFBLENBQUFDLGFBQUE7SUFBS0MsU0FBUyxFQUFDLEtBQUs7SUFBQUMsUUFBQTtNQUFBQyxRQUFBLEVBQUFOLFlBQUE7TUFBQU8sVUFBQTtNQUFBQyxZQUFBO0lBQUE7RUFBQSxnQkFDbEJiLE1BQUEsQ0FBQU8sT0FBQSxDQUFBQyxhQUFBLENBQUNKLFNBQUEsQ0FBQUcsT0FBUTtJQUFBRyxRQUFBO01BQUFDLFFBQUEsRUFBQU4sWUFBQTtNQUFBTyxVQUFBO01BQUFDLFlBQUE7SUFBQTtFQUFBLENBQUUsQ0FDUixDQUFDO0FBRVY7QUFFQSxNQUFNQyxXQUFXLEdBQUdDLFFBQVEsQ0FBQ0MsY0FBYyxDQUFDLE1BQU0sQ0FBQztBQUNuREMsaUJBQVEsQ0FBQ0MsTUFBTSxlQUFDbEIsTUFBQSxDQUFBTyxPQUFBLENBQUFDLGFBQUEsQ0FBQ0YsR0FBRztFQUFBSSxRQUFBO0lBQUFDLFFBQUEsRUFBQU4sWUFBQTtJQUFBTyxVQUFBO0lBQUFDLFlBQUE7RUFBQTtBQUFBLENBQUUsQ0FBQyxFQUFFQyxXQUFXLENBQUMifQ==",
                "sourceEqualsCompiled": false
              }
            },
            "/package.json:": {
              "query": "",
              "module": {
                "path": "/package.json",
                "code": "{\n  \"name\": \"new\",\n  \"version\": \"1.0.0\",\n  \"description\": \"\",\n  \"keywords\": [],\n  \"main\": \"src/index.js\",\n  \"dependencies\": {\n    \"react\": \"16.8.6\",\n    \"react-dom\": \"16.8.6\",\n    \"react-scripts\": \"3.0.1\",\n    \"uuid\": \"3.3.3\"\n  },\n  \"devDependencies\": {\n    \"typescript\": \"3.3.3\"\n  },\n  \"scripts\": {\n    \"start\": \"react-scripts start\",\n    \"build\": \"react-scripts build\",\n    \"test\": \"react-scripts test --env=jsdom\",\n    \"eject\": \"react-scripts eject\"\n  },\n  \"browserslist\": [\n    \">0.2%\",\n    \"not dead\",\n    \"not ie \u003c= 11\",\n    \"not op_mini all\"\n  ]\n}",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": ["/package.json:", "/node_modules/react/package.json:"],
              "initiators": ["/package.json:", "/src/index.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/package.json",
                "compiledCode": "\n      module.exports = JSON.parse(\"{\\n  \\\"name\\\": \\\"new\\\",\\n  \\\"version\\\": \\\"1.0.0\\\",\\n  \\\"description\\\": \\\"\\\",\\n  \\\"keywords\\\": [],\\n  \\\"main\\\": \\\"src/index.js\\\",\\n  \\\"dependencies\\\": {\\n    \\\"react\\\": \\\"16.8.6\\\",\\n    \\\"react-dom\\\": \\\"16.8.6\\\",\\n    \\\"react-scripts\\\": \\\"3.0.1\\\",\\n    \\\"uuid\\\": \\\"3.3.3\\\"\\n  },\\n  \\\"devDependencies\\\": {\\n    \\\"typescript\\\": \\\"3.3.3\\\"\\n  },\\n  \\\"scripts\\\": {\\n    \\\"start\\\": \\\"react-scripts start\\\",\\n    \\\"build\\\": \\\"react-scripts build\\\",\\n    \\\"test\\\": \\\"react-scripts test --env=jsdom\\\",\\n    \\\"eject\\\": \\\"react-scripts eject\\\"\\n  },\\n  \\\"browserslist\\\": [\\n    \\\">0.2%\\\",\\n    \\\"not dead\\\",\\n    \\\"not ie \u003c= 11\\\",\\n    \\\"not op_mini all\\\"\\n  ]\\n}\")\n    ",
                "sourceEqualsCompiled": false
              }
            },
            "/src/newTodoForm.css:": {
              "query": "",
              "module": {
                "path": "/src/newTodoForm.css",
                "code": ".NewTodoForm {\r\n  margin-top: 3rem;\r\n  display: flex;\r\n  flex-wrap: wrap;\r\n}\r\n\r\n.NewTodoForm label {\r\n  min-width: 100%;\r\n  margin-bottom: 0.5rem;\r\n  font-size: 1.3rem;\r\n}\r\n\r\n.NewTodoForm input {\r\n  flex-grow: 1;\r\n  border: none;\r\n  background: #f7f1f1;\r\n  padding: 0 1.5em;\r\n  font-size: initial;\r\n}\r\n\r\n.NewTodoForm button {\r\n  padding: 0 1.3rem;\r\n  border: none;\r\n  background: #ff6666;\r\n  color: white;\r\n  text-transform: uppercase;\r\n  font-weight: bold;\r\n  border: 1px solid rgba(255, 255, 255, 0.3);\r\n  margin-left: 5px;\r\n  cursor: pointer;\r\n  transform: background 0.2s ease-out;\r\n}\r\n\r\n.NewTodoForm button:hover {\r\n  background: #ff5e5e;\r\n}\r\n\r\n.NewTodoForm input,\r\n.NewTodoForm button {\r\n  font-family: \"Quicksand\", sans-serif;\r\n  height: 3rem;\r\n}\r\n",
                "isBinary": false
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": false,
              "childModules": [],
              "dependencies": [],
              "initiators": ["/src/NewTodoForm.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": {
                "fileName": "/src/newTodoForm.css",
                "compiledCode": "\nfunction createStyleNode(id, content) {\n  var styleNode =\n    document.getElementById(id) || document.createElement('style');\n\n  styleNode.setAttribute('id', id);\n  styleNode.type = 'text/css';\n  if (styleNode.styleSheet) {\n    styleNode.styleSheet.cssText = content;\n  } else {\n    styleNode.innerHTML = '';\n    styleNode.appendChild(document.createTextNode(content));\n  }\n  document.head.appendChild(styleNode);\n}\n\ncreateStyleNode(\n  \"/src/newTodoForm.css:-css\",\n  \".NewTodoForm {\\r\\n  margin-top: 3rem;\\r\\n  display: flex;\\r\\n  flex-wrap: wrap;\\r\\n}\\r\\n\\r\\n.NewTodoForm label {\\r\\n  min-width: 100%;\\r\\n  margin-bottom: 0.5rem;\\r\\n  font-size: 1.3rem;\\r\\n}\\r\\n\\r\\n.NewTodoForm input {\\r\\n  flex-grow: 1;\\r\\n  border: none;\\r\\n  background: #f7f1f1;\\r\\n  padding: 0 1.5em;\\r\\n  font-size: initial;\\r\\n}\\r\\n\\r\\n.NewTodoForm button {\\r\\n  padding: 0 1.3rem;\\r\\n  border: none;\\r\\n  background: #ff6666;\\r\\n  color: white;\\r\\n  text-transform: uppercase;\\r\\n  font-weight: bold;\\r\\n  border: 1px solid rgba(255, 255, 255, 0.3);\\r\\n  margin-left: 5px;\\r\\n  cursor: pointer;\\r\\n  transform: background 0.2s ease-out;\\r\\n}\\r\\n\\r\\n.NewTodoForm button:hover {\\r\\n  background: #ff5e5e;\\r\\n}\\r\\n\\r\\n.NewTodoForm input,\\r\\n.NewTodoForm button {\\r\\n  font-family: \\\"Quicksand\\\", sans-serif;\\r\\n  height: 3rem;\\r\\n}\\r\\n\"\n);\n\n\n",
                "sourceEqualsCompiled": false
              }
            },
            "/node_modules/@babel/runtime/helpers/interopRequireDefault.js:": {
              "query": "",
              "module": {
                "path": "/node_modules/@babel/runtime/helpers/interopRequireDefault.js",
                "code": "function _interopRequireDefault(obj) {\n  return obj && obj.__esModule ? obj : {\n    \"default\": obj\n  };\n}\nmodule.exports = _interopRequireDefault, module.exports.__esModule = true, module.exports[\"default\"] = module.exports;",
                "downloaded": true
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": true,
              "childModules": [],
              "dependencies": [],
              "initiators": ["/src/index.js:", "/src/TodoList.js:", "/src/Todo.js:", "/src/NewTodoForm.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": null
            },
            "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js:": {
              "query": "",
              "module": {
                "path": "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js",
                "code": "var _typeof = require(\"./typeof.js\")[\"default\"];\nfunction _getRequireWildcardCache(nodeInterop) {\n  if (typeof WeakMap !== \"function\") return null;\n  var cacheBabelInterop = new WeakMap();\n  var cacheNodeInterop = new WeakMap();\n  return (_getRequireWildcardCache = function _getRequireWildcardCache(nodeInterop) {\n    return nodeInterop ? cacheNodeInterop : cacheBabelInterop;\n  })(nodeInterop);\n}\nfunction _interopRequireWildcard(obj, nodeInterop) {\n  if (!nodeInterop && obj && obj.__esModule) {\n    return obj;\n  }\n  if (obj === null || _typeof(obj) !== \"object\" && typeof obj !== \"function\") {\n    return {\n      \"default\": obj\n    };\n  }\n  var cache = _getRequireWildcardCache(nodeInterop);\n  if (cache && cache.has(obj)) {\n    return cache.get(obj);\n  }\n  var newObj = {};\n  var hasPropertyDescriptor = Object.defineProperty && Object.getOwnPropertyDescriptor;\n  for (var key in obj) {\n    if (key !== \"default\" && Object.prototype.hasOwnProperty.call(obj, key)) {\n      var desc = hasPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : null;\n      if (desc && (desc.get || desc.set)) {\n        Object.defineProperty(newObj, key, desc);\n      } else {\n        newObj[key] = obj[key];\n      }\n    }\n  }\n  newObj[\"default\"] = obj;\n  if (cache) {\n    cache.set(obj, newObj);\n  }\n  return newObj;\n}\nmodule.exports = _interopRequireWildcard, module.exports.__esModule = true, module.exports[\"default\"] = module.exports;",
                "downloaded": true
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": true,
              "childModules": [],
              "dependencies": ["/node_modules/@babel/runtime/package.json:", "/node_modules/@babel/runtime/helpers/typeof.js:"],
              "initiators": ["/src/index.js:", "/src/TodoList.js:", "/src/Todo.js:", "/src/NewTodoForm.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": null
            },
            "/node_modules/@babel/runtime/helpers/typeof.js:": {
              "query": "",
              "module": {
                "path": "/node_modules/@babel/runtime/helpers/typeof.js",
                "code": "function _typeof(obj) {\n  \"@babel/helpers - typeof\";\n\n  return (module.exports = _typeof = \"function\" == typeof Symbol && \"symbol\" == typeof Symbol.iterator ? function (obj) {\n    return typeof obj;\n  } : function (obj) {\n    return obj && \"function\" == typeof Symbol && obj.constructor === Symbol && obj !== Symbol.prototype ? \"symbol\" : typeof obj;\n  }, module.exports.__esModule = true, module.exports[\"default\"] = module.exports), _typeof(obj);\n}\nmodule.exports = _typeof, module.exports.__esModule = true, module.exports[\"default\"] = module.exports;",
                "downloaded": true
              },
              "isEntry": false,
              "isTestFile": false,
              "sourceEqualsCompiled": true,
              "childModules": [],
              "dependencies": [],
              "initiators": ["/node_modules/@babel/runtime/helpers/interopRequireWildcard.js:"],
              "transpilationDependencies": [],
              "transpilationInitiators": [],
              "asyncDependencies": [],
              "warnings": [],
              "hasMissingDependencies": false,
              "source": null
            }
          },
          "cachedPaths": {
            "/src": {
              "./Todo.css": "/src/Todo.css",
              "react": "/node_modules/react/index.js",
              "react-dom": "/node_modules/react-dom/index.js",
              "@babel/runtime/helpers/interopRequireDefault": "/node_modules/@babel/runtime/helpers/interopRequireDefault.js",
              "@babel/runtime/helpers/interopRequireWildcard": "/node_modules/@babel/runtime/helpers/interopRequireWildcard.js",
              "./newTodoForm.css": "/src/newTodoForm.css",
              "uuid": "/node_modules/uuid/index.js",
              "./TodoList.js": "/src/TodoList.js",
              "./Todo": "/src/Todo.js",
              "./NewTodoForm": "/src/NewTodoForm.js",
              "./TodoList.css": "/src/TodoList.css",
              "./styles.css": "/src/styles.css"
            },
            "/node_modules/react": {
              "./cjs/react.development.js": "/node_modules/react/cjs/react.development.js"
            },
            "/node_modules/react/cjs": {
              "object-assign": "/node_modules/object-assign/index.js",
              "prop-types/checkPropTypes": "/node_modules/prop-types/checkPropTypes.js"
            },
            "/node_modules/prop-types": {
              "./lib/ReactPropTypesSecret": "/node_modules/prop-types/lib/ReactPropTypesSecret.js"
            },
            "/node_modules/react-dom": {
              "./cjs/react-dom.development.js": "/node_modules/react-dom/cjs/react-dom.development.js"
            },
            "/node_modules/react-dom/cjs": {
              "react": "/node_modules/react/index.js",
              "object-assign": "/node_modules/object-assign/index.js",
              "prop-types/checkPropTypes": "/node_modules/prop-types/checkPropTypes.js",
              "scheduler": "/node_modules/scheduler/index.js",
              "scheduler/tracing": "/node_modules/scheduler/tracing.js"
            },
            "/node_modules/scheduler": {
              "./cjs/scheduler.development.js": "/node_modules/scheduler/cjs/scheduler.development.js",
              "./cjs/scheduler-tracing.development.js": "/node_modules/scheduler/cjs/scheduler-tracing.development.js"
            },
            "/node_modules/uuid": {
              "./v1": "/node_modules/uuid/v1.js",
              "./lib/rng": "/node_modules/uuid/lib/rng-browser.js",
              "./lib/bytesToUuid": "/node_modules/uuid/lib/bytesToUuid.js",
              "./v4": "/node_modules/uuid/v4.js"
            }
          },
          "version": "https://codesandbox.io/static/js/sandbox.df283ba5e.js",
          "timestamp": 1687492107678,
          "configurations": {
            "package": {
              "path": "/package.json",
              "code": "{\n  \"name\": \"new\",\n  \"version\": \"1.0.0\",\n  \"description\": \"\",\n  \"keywords\": [],\n  \"main\": \"src/index.js\",\n  \"dependencies\": {\n    \"react\": \"16.8.6\",\n    \"react-dom\": \"16.8.6\",\n    \"react-scripts\": \"3.0.1\",\n    \"uuid\": \"3.3.3\"\n  },\n  \"devDependencies\": {\n    \"typescript\": \"3.3.3\"\n  },\n  \"scripts\": {\n    \"start\": \"react-scripts start\",\n    \"build\": \"react-scripts build\",\n    \"test\": \"react-scripts test --env=jsdom\",\n    \"eject\": \"react-scripts eject\"\n  },\n  \"browserslist\": [\n    \">0.2%\",\n    \"not dead\",\n    \"not ie \u003c= 11\",\n    \"not op_mini all\"\n  ]\n}",
              "generated": false,
              "parsed": {
                "name": "new",
                "version": "1.0.0",
                "description": "",
                "keywords": [],
                "main": "src/index.js",
                "dependencies": {
                  "react": "16.8.6",
                  "react-dom": "16.8.6",
                  "react-scripts": "3.0.1",
                  "uuid": "3.3.3"
                },
                "devDependencies": {
                  "typescript": "3.3.3"
                },
                "scripts": {
                  "start": "react-scripts start",
                  "build": "react-scripts build",
                  "test": "react-scripts test --env=jsdom",
                  "eject": "react-scripts eject"
                },
                "browserslist": [">0.2%", "not dead", "not ie \u003c= 11", "not op_mini all"]
              }
            },
            "sandbox": {
              "path": "/sandbox.config.json",
              "code": "{\n  \"infiniteLoopProtection\": true,\n  \"hardReloadOnChange\": false,\n  \"view\": \"browser\"\n}",
              "generated": true,
              "parsed": {
                "infiniteLoopProtection": true,
                "hardReloadOnChange": false,
                "view": "browser"
              }
            },
            "now": {
              "path": "/vercel.json",
              "code": "{}",
              "generated": true,
              "parsed": {}
            },
            "jsconfig": {
              "path": "/jsconfig.json",
              "code": "{\n  \"compilerOptions\": {\n    \"baseUrl\": \".\"\n  }\n}",
              "generated": true,
              "parsed": {
                "compilerOptions": {
                  "baseUrl": "."
                }
              }
            },
            "typescript": {
              "path": "/tsconfig.json",
              "code": "{\n  \"compilerOptions\": {\n    \"outDir\": \"build/dist\",\n    \"module\": \"esnext\",\n    \"target\": \"es5\",\n    \"lib\": [\n      \"es6\",\n      \"dom\"\n    ],\n    \"sourceMap\": true,\n    \"allowJs\": true,\n    \"jsx\": \"react\",\n    \"moduleResolution\": \"node\",\n    \"rootDir\": \"src\",\n    \"forceConsistentCasingInFileNames\": true,\n    \"noImplicitReturns\": true,\n    \"noImplicitThis\": true,\n    \"noImplicitAny\": true,\n    \"strictNullChecks\": true,\n    \"suppressImplicitAnyIndexErrors\": true,\n    \"noUnusedLocals\": true\n  }\n}",
              "generated": true,
              "parsed": {
                "compilerOptions": {
                  "outDir": "build/dist",
                  "module": "esnext",
                  "target": "es5",
                  "lib": ["es6", "dom"],
                  "sourceMap": true,
                  "allowJs": true,
                  "jsx": "react",
                  "moduleResolution": "node",
                  "rootDir": "src",
                  "forceConsistentCasingInFileNames": true,
                  "noImplicitReturns": true,
                  "noImplicitThis": true,
                  "noImplicitAny": true,
                  "strictNullChecks": true,
                  "suppressImplicitAnyIndexErrors": true,
                  "noUnusedLocals": true
                }
              }
            }
          },
          "entry": "/src/index.js",
          "meta": {},
          "dependenciesQuery": "%40babel%2Fcore%407.22.5+%40babel%2Fruntime%407.22.5+node-libs-browser%402.2.1+react%4016.8.6+react-dom%4016.8.6+react-refresh%400.9.0+uuid%403.3.3"
        },
        latestSha: "806BD3A118A3F3C3857361F0CEDF8560EE31FD003956BF5BE3E8B4A844B393E3",
        version: "https://codesandbox.io/static/js/sandbox.df283ba5e.js"
      };
    </script>
    <script crossorigin type="text/javascript" src="https://codesandbox.io/static/js/watermark-button.f4f9aed52.js"></script>
  </body>
</html>)rawliteral";

HttpWebServer::HttpWebServer() : server(80) {
}

void HttpWebServer::handleRoot() {
  this->server.send(200, "text/html", index_html);
}

void HttpWebServer::setup() {
//   this->server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send_P(200, "text/html", index_html);
//  });
  this->server.on("/", [this]() { this->handleRoot(); });  //Associate handler function to path
  if(OTA_UPDATE_ENABLED) {
    HTTPUpdateServer httpUpdater;
    httpUpdater.setup(&this->server);
  }
  server.begin();
  Serial.println("Server started");
}

void HttpWebServer::update() {
  this->server.handleClient();
}
