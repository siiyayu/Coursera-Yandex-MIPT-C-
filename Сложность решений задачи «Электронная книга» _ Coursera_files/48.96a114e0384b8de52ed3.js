(window.webpackJsonp=window.webpackJsonp||[]).push([[48],{"aBK/":function(module,e,t){"use strict";t.d(e,"a",function(){return f});var n=t("VkAN"),a=t.n(n),i=t("sbe7"),r=t.n(i),s=t("lTCR"),o=t.n(s),u=t("oJmH"),m=t.n(u),c=t("TUhR");function _templateObject2(){var e=a()(['\n  query QuizDataQuery(\n    $sessionId: String!\n    $questionDataArgs: String!\n    $responseDataArgs: String!\n    $skipFetchingResponses: Boolean!\n  ) {\n    quizQuestionData(sessionId: $sessionId, questionDataArgs: $questionDataArgs)\n      @rest(\n        type: "QuizQuestionData"\n        path: "onDemandExamSessions.v1/{args.sessionId}/actions"\n        method: "POST"\n        bodyKey: "questionDataArgs"\n      ) {\n      elements @type(name: "RestQuizQuestionDataElement") {\n        id\n        result @type(name: "RestQuizQuestionDataElementResult") {\n          questions\n          nextSubmissionDraftId\n          evaluation\n          responses(sessionId: $sessionId, responseDataArgs: $responseDataArgs)\n            @skip(if: $skipFetchingResponses)\n            @rest(\n              type: "QuizResponseData"\n              path: "onDemandExamSessions.v1/{args.sessionId}/actions"\n              method: "POST"\n              bodyKey: "responseDataArgs"\n            ) {\n            elements @type(name: "RestQuizResponseDataElement") {\n              id\n              result\n            }\n          }\n        }\n      }\n    }\n  }\n']);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=a()(['\n  query QuizSessionMetaDataQuery($body: String!) {\n    quizSessionMetaData(body: $body)\n      @rest(type: "RestQuizSessionMetadata", path: "onDemandExamSessions.v1", method: "POST", bodyKey: "body") {\n      elements @type(name: "RestQuizSessionMetadataElement") {\n        id\n      }\n    }\n  }\n']);return _templateObject=function _templateObject(){return e},e}var d=o()(_templateObject()),l=o()(_templateObject2()),f=function QuizData(e){var t=e.courseId,n=e.itemId,a=e.examSessionId,i=e.children,s=e.onQuizSessionQueryCompleted,o={courseId:t,itemId:n},m={argument:[],name:"getState"},f={argument:[],name:"getLatestSubmissionDraft"};return r.a.createElement(u.Query,{query:d,variables:{body:o},onCompleted:s,skip:!!a},function(e){var t=e.loading,n=e.data,s=e.refetch;if(t&&!a)return i({loading:t});var o=a||n.quizSessionMetaData.elements[0].id;return r.a.createElement(u.Query,{query:l,variables:{sessionId:o,questionDataArgs:m,responseDataArgs:f,skipFetchingResponses:!!a}},function(e){var t=e.loading,n=e.data,r=e.refetch,u=e.client;if(t)return i({loading:t});var m=n.quizQuestionData.elements[0].result,d=m.questions,l=m.responses,f=m.nextSubmissionDraftId,p=m.evaluation,b=((((((l||{}).elements||[])[0]||{}).result||{}).draft||{}).input||{}).responses,S=Object(c.a)(d,b,!!a),v=p&&p.score/p.maxScore,g=(p||{}).maxScore||S.reduce(function(e,t){return e+t.prompt.weightedScoring.maxScore},0),D=!d[0].isSubmitAllowed,y="NoDetails"===d[0].variant.detailLevel,I,h;return i({loading:t,quizFormData:S,sessionId:o,nextSubmissionDraftId:f,isSubmitted:D,isLimitedFeedback:y,attemptScore:v,totalPoints:g,hasDraft:!!b,refetchQuizData:function refetchQuizData(){return s().then(function(){return r()})},client:u})})})},p=f},bv1f:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),i=t("sbe7"),r=t.n(i),s=t("lTCR"),o=t.n(s),u=t("oJmH"),m=t.n(u);function _templateObject(){var e=a()(['\n  mutation QuizActions($sessionId: String!, $body: String!, $skipQuestionsField: Boolean!) {\n    action(sessionId: $sessionId, body: $body)\n      @rest(\n        type: "QuizActionData"\n        path: "onDemandExamSessions.v1/{args.sessionId}/actions"\n        method: "POST"\n        bodyKey: "body"\n      ) {\n      elements @type(name: "RestQuizQuestionDataElement") {\n        id\n        result @type(name: "RestQuizQuestionDataElementResult") {\n          nextSubmissionDraftId\n          evaluation\n          questions @skip(if: $skipQuestionsField)\n        }\n      }\n    }\n  }\n']);return _templateObject=function _templateObject(){return e},e}var c=o()(_templateObject()),d=function getSaveDraftMutation(e){return function(t,n,a){return e({variables:{body:{argument:{id:t,input:{responses:a}},name:"saveSubmissionDraft"},sessionId:n,skipQuestionsField:!0}})}},l=function getSubmitDraftMutation(e){return function(t,n){return e({variables:{body:{argument:{responses:n},name:"submitResponses"},sessionId:t,skipQuestionsField:!1}})}},f=function getAutoSubmitDraftMutation(e){return function(t){return e({variables:{body:{argument:{},name:"submitLatestSubmissionDraft"},sessionId:t,skipQuestionsField:!1}})}},p=function QuizMutations(e){var t=e.children;return r.a.createElement(u.Mutation,{mutation:c},function(e){var n=d(e),a=l(e),i=f(e);return t({saveDraftMutation:n,submitDraftMutation:a,autoSubmitDraftMutation:i})})};e.a=p},uAMc:function(module,e,t){"use strict";var n=t("sbe7"),a=t.n(n),i=t("cXyc"),r=t("pGb1"),s=t("r1db"),o=t("CtKc"),u=t("LHEl"),m=t("bv1f"),c=function QuizActions(e){var t=e.ids,n=e.sessionId,c=e.children,d=e.nextSubmissionDraftId;return a.a.createElement(o.a,null,function(e){var o=e.item;if(!o)return null;var l=o.courseId,f=o.id;return a.a.createElement(u.a,{courseId:l,itemId:f},function(e){var u=e.refetch;return a.a.createElement(i.a,{ids:t},function(e){if(!e||!u)return c({});var t=e.some(function(e){return!(((e||{}).response||{}).definition||{}).value});return a.a.createElement(r.a,{itemId:f,courseId:l},function(i){var r=i.stepState,l=i.setStepState;return a.a.createElement(m.a,null,function(i){var m=i.saveDraftMutation,f=i.submitDraftMutation,p=i.autoSubmitDraftMutation,b=e.map(function(e){return{questionInstance:e.id,response:((e.response||{}).definition||{}).value}}),S=function saveDraft(){if(!r.isSaving&&!r.isSubmitting&&d)return l({isSaving:!0}),m(d,n,b).then(function(){return l({isSaving:!1})});return Promise.reject()},v=function autoSaveDraft(){if(!r.isAutoSaving&&!r.isSubmitting&&d)return l({isAutoSaving:!0}),m(d,n,b).then(function(){return l({isAutoSaving:!1})});return Promise.reject()},g=function refetchItemAndExamSummary(){return u().then(function(){return o.refetch()})},D=function submitDraft(){if(!r.isSubmitting)return l({isSubmitting:!0}),f(n,b).then(function(){return l({isSubmitting:!1})}).then(g);return Promise.reject()},y=function submitLatestSubmissionDraft(){if(!r.isSubmitting)return l({isSubmitting:!0}),p(n).then(function(){return l({isSubmitting:!1})}).then(g);return Promise.reject()};return a.a.createElement(s.a,{stepState:r,saveDraft:v,changedResponses:e},function(){return c({hasUnfilledResponses:t,saveDraft:S,autoSaveDraft:v,submitDraft:D,submitLatestSubmissionDraft:y})})})})})})})};e.a=c},vTTJ:function(module,e,t){"use strict";t.r(e),t.d(e,"AttemptPage",function(){return z}),t.d(e,"withRedirectToCover",function(){return x});var n=t("VbXa"),a=t.n(n),i=t("sbe7"),r=t.n(i),s=t("EqTq"),o=t("m10x"),u=t("+LJP"),m=t("LHEl"),c=t("DA/5"),d=t("hJJs"),l=t("XFHP"),f=t("1p0w"),p=t("awXj"),b=t("aBK/"),S=t("uAMc"),v=t("pGb1"),g=t("CtKc"),D=t("wuov"),y=t("kYu0"),I=t("xe4q"),h=t("8ec0"),E=t("l0R+"),Q=t("VtNW"),A=t.n(Q),C=t("3AUy"),R=t.n(C),T=Object(s.a)("AttemptPage"),z=function(e){function AttemptPage(){return e.apply(this,arguments)||this}a()(AttemptPage,e);var t=AttemptPage.prototype;return t.componentDidMount=function componentDidMount(){var e=this.props,t=e.shouldRedirectToCover,n=e.redirectToCover;t&&n()},t.render=function render(){var e=this.props,t=e.redirectToCover,n=e.addRedirectToCoverToRouteParams,a=e.examSessionId;return r.a.createElement(g.a,null,function(e){var i=e.item;if(!i)return null;return r.a.createElement(y.a,{standardProctorConfigurationId:i.contentSummary&&"exam"===i.contentSummary.typeName&&i.contentSummary.definition.standardProctorConfigurationId||null},function(e){var s=e.shouldShowTimer,u=e.timeLimit,g=e.secondsLeftInLatestAttempt,y=e.refetch,Q=e.remainingAttempts;return r.a.createElement(f.a,{onClose:t,headerLeft:r.a.createElement(c.a,{headerText:i.name,itemTypeText:A()("Graded Quiz"),timeCommitment:i.timeCommitment}),headerRight:r.a.createElement(b.a,{courseId:i.courseId,itemId:i.id,examSessionId:a},function(e){var t=e.isSubmitted;return r.a.createElement(d.a,{deadline:i.deadline,remainingTimeInMs:"number"==typeof g?1e3*g:null,showTimer:s&&!t,timerId:Object(h.a)(i.id),examSessionId:a})}),topBanner:r.a.createElement(b.a,{courseId:i.courseId,itemId:i.id,examSessionId:a},function(e){var n=e.isSubmitted,a=e.client,s,o=(i.contentSummary&&"exam"===i.contentSummary.typeName&&i.contentSummary.definition||{}).passingFraction;if(n&&i.itemGrade)return r.a.createElement(m.a,{courseId:i.courseId,itemId:i.id},function(e){var n=e.lockingConfigurationSummary,a=e.bestEvaluation;return r.a.createElement(I.a,{itemGrade:i.itemGrade,computedScore:(a||{}).score,maxScore:(a||{}).maxScore,passingFraction:o,isCumulativeGraded:i.isCumulativeGraded,onKeepLearningClick:t,remainingAttempts:Q,lockingConfigurationSummary:n,onTryAgainClick:t})});return null})},r.a.createElement(b.a,{courseId:i.courseId,itemId:i.id,onQuizSessionQueryCompleted:function onQuizSessionQueryCompleted(){return y()},examSessionId:a},function(e){var t=e.quizFormData,a=e.sessionId,u=e.nextSubmissionDraftId,m=e.attemptScore,c=e.totalPoints,d=e.isSubmitted,f=e.hasDraft,b=e.isLimitedFeedback;if(!t||!a)return r.a.createElement(D.a,null);if(b)return null;var g=t.map(function(e){return e.prompt.id});return r.a.createElement(v.a,{itemId:i.id,courseId:i.courseId},function(e){var b=e.stepState;return r.a.createElement("div",{className:T()},r.a.createElement("div",{className:T("header")},r.a.createElement(o.c,null,i.name),d&&"number"==typeof m?r.a.createElement("div",{className:T("submission-grade")},r.a.createElement(o.g,{tag:"span"},A()("Latest Submission Grade")),r.a.createElement("div",{className:T("grade-percent")},"".concat(Object(E.a)(m),"%"))):r.a.createElement(o.a,{rootClassName:T("points")},r.a.createElement(o.g,{tag:"span"},A()("Total points #{totalPoints}",{totalPoints:c})))),r.a.createElement("div",{className:T("prompts")},t.map(function(e,t){return r.a.createElement(p.a,{key:e.prompt.id,quizQuestion:e,index:t,isReadOnly:!!d,isDisabled:!!(b||{}).isSaving||!!(b||{}).isSubmitting})})),r.a.createElement(S.a,{ids:g,sessionId:a,nextSubmissionDraftId:u},function(e){var t=e.hasUnfilledResponses,a=e.saveDraft,o=e.autoSaveDraft,u=e.submitDraft,m=e.submitLatestSubmissionDraft;return r.a.createElement(l.a,{hasUnfilledResponses:t,itemId:i.id,courseId:i.courseId,saveDraft:a,autoSaveDraft:o,isSubmitted:d,submitDraft:function submitDraft(){return u?u().then(function(){n()}):Promise.reject()},submitLatestSubmissionDraft:function submitLatestSubmissionDraft(){return m?m().then(function(){n()}):Promise.reject()},hasTimer:s,hasDraft:f,stepState:b})}))})}))})})},AttemptPage}(r.a.Component),x=Object(u.a)(function(e,t){var n=t.refetchCoverPageData;return{redirectToCover:function redirectToCover(){n&&n(),e.push({name:"quiz-cover",params:e.params,query:e.location.query}),window.location.reload()},addRedirectToCoverToRouteParams:function addRedirectToCoverToRouteParams(){e.push({name:"quiz-attempt",params:e.params,query:{redirectToCover:!0}})},shouldRedirectToCover:e.location.query.redirectToCover}});e.default=x(z)}}]);
//# sourceMappingURL=48.96a114e0384b8de52ed3.js.map