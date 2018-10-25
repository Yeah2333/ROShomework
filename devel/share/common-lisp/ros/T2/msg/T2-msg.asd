
(cl:in-package :asdf)

(defsystem "T2-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "laserpoint" :depends-on ("_package_laserpoint"))
    (:file "_package_laserpoint" :depends-on ("_package"))
    (:file "postionAction" :depends-on ("_package_postionAction"))
    (:file "_package_postionAction" :depends-on ("_package"))
    (:file "postionActionFeedback" :depends-on ("_package_postionActionFeedback"))
    (:file "_package_postionActionFeedback" :depends-on ("_package"))
    (:file "postionActionGoal" :depends-on ("_package_postionActionGoal"))
    (:file "_package_postionActionGoal" :depends-on ("_package"))
    (:file "postionActionResult" :depends-on ("_package_postionActionResult"))
    (:file "_package_postionActionResult" :depends-on ("_package"))
    (:file "postionFeedback" :depends-on ("_package_postionFeedback"))
    (:file "_package_postionFeedback" :depends-on ("_package"))
    (:file "postionGoal" :depends-on ("_package_postionGoal"))
    (:file "_package_postionGoal" :depends-on ("_package"))
    (:file "postionResult" :depends-on ("_package_postionResult"))
    (:file "_package_postionResult" :depends-on ("_package"))
  ))