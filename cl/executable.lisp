(defun main ()
(format t "hello world! ~a~%" (nth 1 si::*command-args*))
(force-output)
(quit))

(setf system::*top-level-hook* #'main)
(system::save-system "executable.exe") 