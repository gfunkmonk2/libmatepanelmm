doxygen_configfile = Doxyfile
web_path_reference = /home/groups/g/gt/gtkmm/htdocs/gtkmm2DONTUPLOADTHIS/reference
beautify_docs = @GMM_PROCDIR@/beautify_docs.pl

EXTRA_DIST	= README $(doxygen_configfile)


docs-reference: $(doxygen_configfile)
	doxygen $(doxygen_configfile)
#	$(PERL_PATH) $(beautify_docs) html

docs-reference-html: docs-reference

libmatepanelappletmm-reference-html.tar.gz: docs-reference-html
	tar -cf - $< | gzip > $@


post-html: docs-reference
	(cd html && tar -cf - *.html *.gif *.css | gzip -3 | \
	 ssh $$SSH_OPT $$USER@gtkmm.sourceforge.net "cd $(web_path_reference)/html ; gunzip | tar -xvf - ; chmod a+r,g+w * ; chgrp gtkmm *")


all-local: docs-reference

clean-local:
	-rm -rf html
	-rm -f libmatepanelappletmm-reference-html.tar.gz
