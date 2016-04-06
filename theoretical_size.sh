spalte_a="abcdefghijklmnopqrstuvwxyz"
spalte_b="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
spalte_c="aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz"
spalte_d="0123456789"
spalte_e="0123456789012345678901234567890123456789012345678901234567890123456789"
spalte_f="abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"
complete_row=${spalte_a}${spalte_b}${spalte_c}${spalte_d}${spalte_e}${spalte_f}
echo "raw size: memory per row: ${#complete_row} bytes"
