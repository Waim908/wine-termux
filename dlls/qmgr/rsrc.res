        ��  ��                  h  8   W I N E _ R E G I S T R Y   ��     0           HKCR
{
    NoRemove AppID
    {
        '{69AD4AEE-51BE-439B-A92C-86AE490E8B30}' { val LocalService = s 'BITS' }
        BITS { val AppID = s '{69AD4AEE-51BE-439B-A92C-86AE490E8B30}' }
    }
    NoRemove CLSID
    {
        '{4991D34B-80A1-4291-83B6-3328366B9097}'
        {
            val AppID = s '{69AD4AEE-51BE-439B-A92C-86AE490E8B30}'
        }
    }
}
