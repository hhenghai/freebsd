/* This file is automatically generated from wc-checks.sql and .dist_sandbox/subversion-1.8.0/subversion/libsvn_wc/token-map.h.
 * Do not edit this file -- edit the source and rerun gen-make.py */

#define STMT_VERIFICATION_TRIGGERS 0
#define STMT_0_INFO {"STMT_VERIFICATION_TRIGGERS", NULL}
#define STMT_0 \
  "CREATE TEMPORARY TRIGGER no_repository_updates BEFORE UPDATE ON repository " \
  "BEGIN " \
  "  SELECT RAISE(FAIL, 'Updates to REPOSITORY are not allowed.'); " \
  "END; " \
  "CREATE TEMPORARY TRIGGER validation_01 BEFORE INSERT ON nodes " \
  "WHEN NOT ((new.local_relpath = '' AND new.parent_relpath IS NULL) " \
  "          OR (relpath_depth(new.local_relpath) " \
  "              = relpath_depth(new.parent_relpath) + 1)) " \
  "BEGIN " \
  "  SELECT RAISE(FAIL, 'WC DB validity check 01 failed'); " \
  "END; " \
  "CREATE TEMPORARY TRIGGER validation_02 BEFORE INSERT ON nodes " \
  "WHEN NOT new.op_depth <= relpath_depth(new.local_relpath) " \
  "BEGIN " \
  "  SELECT RAISE(FAIL, 'WC DB validity check 02 failed'); " \
  "END; " \
  "CREATE TEMPORARY TRIGGER validation_03 BEFORE INSERT ON nodes " \
  "WHEN NOT ( " \
  "    (new.op_depth = relpath_depth(new.local_relpath)) " \
  "    OR " \
  "    (EXISTS (SELECT 1 FROM nodes " \
  "              WHERE wc_id = new.wc_id AND op_depth = new.op_depth " \
  "                AND local_relpath = new.parent_relpath)) " \
  "  ) " \
  " AND NOT (new.file_external IS NOT NULL AND new.op_depth = 0) " \
  "BEGIN " \
  "  SELECT RAISE(FAIL, 'WC DB validity check 03 failed'); " \
  "END; " \
  "CREATE TEMPORARY TRIGGER validation_04 BEFORE INSERT ON actual_node " \
  "WHEN NOT (new.local_relpath = '' " \
  "          OR EXISTS (SELECT 1 FROM nodes " \
  "                       WHERE wc_id = new.wc_id " \
  "                         AND local_relpath = new.parent_relpath)) " \
  "BEGIN " \
  "  SELECT RAISE(FAIL, 'WC DB validity check 04 failed'); " \
  "END; " \
  ""

#define WC_CHECKS_SQL_DECLARE_STATEMENTS(varname) \
  static const char * const varname[] = { \
    STMT_0, \
    NULL \
  }

#define WC_CHECKS_SQL_DECLARE_STATEMENT_INFO(varname) \
  static const char * const varname[][2] = { \
    STMT_0_INFO, \
    {NULL, NULL} \
  }
