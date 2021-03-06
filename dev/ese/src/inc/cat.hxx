// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

extern const CHAR   szMSU1[];
extern const CHAR   szMSU[];
extern const CHAR   szMSO[];
extern const CHAR   szMSOShadow[];
extern const CHAR   szMSOIdIndex[];
extern const CHAR   szMSONameIndex[];
extern const CHAR   szMSORootObjectsIndex[];

extern const CHAR   szMSObjids[];

extern const CHAR   szMSLocales[];


typedef USHORT  SYSOBJ;
const SYSOBJ    sysobjNil               = 0;
const SYSOBJ    sysobjTable             = 1;
const SYSOBJ    sysobjColumn            = 2;
const SYSOBJ    sysobjIndex             = 3;
const SYSOBJ    sysobjLongValue         = 4;
const SYSOBJ    sysobjCallback          = 5;


const ULONG iMSO_ObjidTable             = 0;
const ULONG iMSO_Type                   = 1;
const ULONG iMSO_Id                     = 2;
const ULONG iMSO_Name                   = 3;
const ULONG iMSO_Coltyp                 = 4;
const ULONG iMSO_PgnoFDP                = 4;
const ULONG iMSO_SpaceUsage             = 5;
const ULONG iMSO_Flags                  = 6;
const ULONG iMSO_Localization           = 7;
const ULONG iMSO_Pages                  = 7;
const ULONG iMSO_Stats                  = 8;
const ULONG iMSO_RootFlag               = 9;
const ULONG iMSO_TemplateTable          = 10;
const ULONG iMSO_Callback               = 10;
const ULONG iMSO_RecordOffset           = 11;
const ULONG iMSO_DefaultValue           = 12;
const ULONG iMSO_KeyFldIDs              = 13;
const ULONG iMSO_VarSegMac              = 14;
const ULONG iMSO_ConditionalColumns     = 15;
const ULONG iMSO_LCMapFlags             = 16;
const ULONG iMSO_KeyMost                = 17;
const ULONG iMSO_TupleLimits            = 18;
const ULONG iMSO_Version                = 19;
const ULONG iMSO_SortID                 = 20;
const ULONG iMSO_CallbackData           = 21;
const ULONG iMSO_CallbackDependencies   = 22;
const ULONG iMSO_SeparateLVThreshold    = 23;
const ULONG iMSO_SpaceHint              = 24;
const ULONG iMSO_SpaceLVDeferredHints   = 25;
const ULONG iMSO_LocaleName             = 26;
const ULONG iMSO_LVChunkMax             = 27;

const ULONG idataMSOMax                 = 28;


const FID   fidMSO_ObjidTable           = fidFixedLeast;
const FID   fidMSO_Type                 = fidFixedLeast+1;
const FID   fidMSO_Id                   = fidFixedLeast+2;
const FID   fidMSO_Coltyp               = fidFixedLeast+3;
const FID   fidMSO_PgnoFDP              = fidFixedLeast+3;
const FID   fidMSO_SpaceUsage           = fidFixedLeast+4;
const FID   fidMSO_Flags                = fidFixedLeast+5;
const FID   fidMSO_Pages                = fidFixedLeast+6;
const FID   fidMSO_Localization         = fidFixedLeast+6;
const FID   fidMSO_RootFlag             = fidFixedLeast+7;
const FID   fidMSO_RecordOffset         = fidFixedLeast+8;
const FID   fidMSO_LCMapFlags           = fidFixedLeast+9;
const FID   fidMSO_KeyMost              = fidFixedLeast+10;
const FID   fidMSO_LVChunkMax           = fidFixedLeast+11;

const FID   fidMSO_FixedLast            = fidMSO_LVChunkMax;

const FID   fidMSO_Name                 = fidVarLeast;
const FID   fidMSO_Stats                = fidVarLeast+1;
const FID   fidMSO_TemplateTable        = fidVarLeast+2;
const FID   fidMSO_Callback             = fidVarLeast+2;
const FID   fidMSO_DefaultValue         = fidVarLeast+3;
const FID   fidMSO_KeyFldIDs            = fidVarLeast+4;
const FID   fidMSO_VarSegMac            = fidVarLeast+5;
const FID   fidMSO_ConditionalColumns   = fidVarLeast+6;
const FID   fidMSO_TupleLimits          = fidVarLeast+7;
const FID   fidMSO_Version              = fidVarLeast+8;
const FID   fidMSO_SortID               = fidVarLeast+9;

const FID   fidMSO_VarLast              = fidMSO_SortID;

const FID   fidMSO_CallbackData         = fidTaggedLeast;
const FID   fidMSO_CallbackDependencies = fidTaggedLeast+1;
const FID   fidMSO_SeparateLVThreshold  = fidTaggedLeast+2;
const FID   fidMSO_SpaceHints           = fidTaggedLeast+3;
const FID   fidMSO_SpaceLVDeferredHints = fidTaggedLeast+4;
const FID   fidMSO_LocaleName           = fidTaggedLeast+5;

const FID   fidMSO_TaggedLast           = fidMSO_LocaleName;


extern const OBJID  objidFDPMSO;
extern const OBJID  objidFDPMSOShadow;
const OBJID objidFDPMSO_NameIndex               = 4;
const OBJID objidFDPMSO_RootObjectIndex         = 5;

INLINE BOOL FCATISystemObjid( OBJID objid )
{
    return objid <= objidFDPMSO_RootObjectIndex;
}

INLINE BOOL FCATMsysObjectsTableIndex( _In_ const OBJID objidTable )
{
    return ( objidTable == objidFDPMSO_NameIndex || objidTable == objidFDPMSO_RootObjectIndex );
}



const CPG   cpgMSOInitial                       = 20;
const PGNO  pgnoFDPMSO                          = 4;
const PGNO  pgnoFDPMSO_NameIndex                = 7;
const PGNO  pgnoFDPMSO_RootObjectIndex          = 10;

const CPG   cpgMSOShadowInitial2K               = 6;
const CPG   cpgMSOShadowInitial4K               = 5;
const CPG   cpgMSOShadowInitial8K               = 5;
const PGNO  pgnoFDPMSOShadow                    = 24;

INLINE CPG CpgCATShadowInitial( const ULONG cbPage )
{
    switch( cbPage )
    {
    case 2 * 1024:
        return cpgMSOShadowInitial2K;
    case 4 * 1024:
        return cpgMSOShadowInitial4K;
    }
    return cpgMSOShadowInitial8K;
}

INLINE BOOL FCATBaseSystemFDP( const PGNO pgnoT )
{
    if ( pgnoT == pgnoSystemRoot ||
            pgnoT == pgnoFDPMSO ||
            pgnoT == pgnoFDPMSO_NameIndex ||
            pgnoT == pgnoFDPMSO_RootObjectIndex ||
            pgnoT == pgnoFDPMSOShadow )
    {
        return fTrue;
    }
    return fFalse;
}

ERR ErrCATCheckJetSpaceHints(
    _In_ const LONG             cbPageSize,
    _Inout_ JET_SPACEHINTS *    pSpaceHints,
    _In_ BOOL                   fAllowCorrection = fFalse
    );

ULONG * PulCATIGetExtendedHintsStart(
    __in const SYSOBJ                   sysobj,
    __in const BOOL                     fDeferredLongValueHints,
    __in const JET_SPACEHINTS * const   pSpacehints,
    __out ULONG *                       pcTotalHints );

INLINE BOOL FCATHasExtendedHints(  __in const SYSOBJ sysobj, const JET_SPACEHINTS * pjsph )
{
    ULONG cTotalHints;
    ULONG * pulHints =  PulCATIGetExtendedHintsStart( sysobj, fFalse, pjsph, &cTotalHints );
    while( cTotalHints > 0 && pulHints[cTotalHints-1] == 0 )
    {
        cTotalHints--;
    }
    return cTotalHints > 0;
}



const ULONG cbExtendedSpaceHints = 1 + sizeof( JET_SPACEHINTS );

PERSISTED
const BYTE  bCATExtendedSpaceHintsVersion = 1;

enum
{
    eJSPHDefaultCatalog = 0,
    eJSPHDefaultUserTable = 0,
    eJSPHDefaultUserIndex = 0,
    eJSPHDefaultHeavyWater = 1,
    eJSPHDefaultMax
};

extern const JET_SPACEHINTS g_jsphSystemDefaults[ eJSPHDefaultMax ];

#define PSystemSpaceHints( eJSPHDefault )   ( &( g_jsphSystemDefaults[eJSPHDefault] ) )
#define FIsSystemSpaceHint( pSpaceHints )   ( ( (&(g_jsphSystemDefaults[0])) <= (pSpaceHints) ) && ( (pSpaceHints) < ((&g_jsphSystemDefaults[0]) + eJSPHDefaultMax ) ) )




INLINE BOOL FCATUnicodeFixupTable( IN const CHAR * const szTableName )
{
    return (    0 == UtilCmpName( szTableName, szMSU ) ||
                0 == UtilCmpName( szTableName, szMSU1 ) );
}

INLINE BOOL FCATObjidsTable( const CHAR * const szTableName )
{
    return ( 0 == UtilCmpName( szTableName, szMSObjids ) );
}

INLINE BOOL FCATLocalesTable( const CHAR * const szTableName )
{
    return ( 0 == UtilCmpName( szTableName, szMSLocales ) );
}

INLINE BOOL FCATSystemTable( const PGNO pgnoTableFDP )
{
    return ( pgnoFDPMSO == pgnoTableFDP
            || pgnoFDPMSOShadow == pgnoTableFDP );
}

INLINE BOOL FCATSystemTableByObjid( const OBJID objidTableFDP )
{
    return ( objidFDPMSO == objidTableFDP
            || objidFDPMSOShadow == objidTableFDP );
}

INLINE BOOL FCATSystemTable( const CHAR *szTableName )
{
    return ( 0 == UtilCmpName( szTableName, szMSO )
             || 0 == UtilCmpName( szTableName, szMSOShadow ) );
}

INLINE BOOL FCATShadowSystemTable( const CHAR *szTableName )
{
    return ( 0 == UtilCmpName( szTableName, szMSOShadow ) );
}

INLINE PGNO PgnoCATTableFDP( const CHAR *szTableName )
{
    Assert( FCATSystemTable( szTableName ) );
    if ( 0 == UtilCmpName( szTableName, szMSO ) )
        return pgnoFDPMSO;
    else
    {
        Assert( 0 == UtilCmpName( szTableName, szMSOShadow ) );
        return pgnoFDPMSOShadow;
    }
}

INLINE PGNO PgnoCATTableFDP( const OBJID objidFDP )
{
    Assert( FCATSystemTableByObjid( objidFDP ) );
    if ( objidFDPMSO == objidFDP )
        return pgnoFDPMSO;
    else
    {
        Assert( objidFDPMSOShadow == objidFDP );
        return pgnoFDPMSOShadow;
    }
}

INLINE PGNO ObjidCATTable( const PGNO pgnoFDP )
{
    Assert( FCATSystemTable( pgnoFDP ) );
    if ( pgnoFDPMSO == pgnoFDP )
        return objidFDPMSO;
    else
    {
        Assert( pgnoFDPMSOShadow == pgnoFDP );
        return objidFDPMSOShadow;
    }
}

INLINE PGNO ObjidCATTable( const CHAR *szTableName )
{
    Assert( FCATSystemTable( szTableName ) );
    if ( 0 == UtilCmpName( szTableName, szMSO ) )
        return objidFDPMSO;
    else
    {
        Assert( 0 == UtilCmpName( szTableName, szMSOShadow ) );
        return objidFDPMSOShadow;
    }
}

ERR ErrREPAIRCATCreate(
    PIB *ppib,
    const IFMP ifmp,
    const OBJID objidNameIndex,
    const OBJID objidRootObjectsIndex,
    const BOOL  fInRepair = fFalse,
    const BOOL fReplayInitialLoggedCreateDB = fFalse    );

ERR ErrCATCreate( PIB *ppib, const IFMP ifmp, const BOOL fReplayInitialLoggedCreateDB );

INLINE ERR ErrCATOpen(
    PIB         *ppib,
    const IFMP  ifmp,
    FUCB        **ppfucbCatalog,
    const BOOL  fShadow = fFalse )
{
    ERR         err;

    Assert( dbidTemp != g_rgfmp[ifmp].Dbid() );
    err = ErrFILEOpenTable(
                ppib,
                ifmp,
                ppfucbCatalog,
                fShadow ? szMSOShadow : szMSO,
                bitTableUpdatableDuringRecovery );
    if ( err >= 0 )
        FUCBSetSystemTable( *ppfucbCatalog );

    return err;

}

INLINE ERR ErrCATClose( PIB *ppib, FUCB *pfucbCatalog )
{
    Assert( pfucbNil != pfucbCatalog );
    return ErrFILECloseTable( ppib, pfucbCatalog );
}

ERR ErrCATAddTable(
    PIB                             *ppib,
    FUCB                            *pfucbCatalog,
    const PGNO                      pgnoTableFDP,
    const OBJID                     objidTable,
    const CHAR                      *szTableName,
    const CHAR                      *szTemplateTableName,
    const ULONG                     ulFlags,
    const JET_SPACEHINTS * const    pSpacehints,
    const ULONG                     cbSeparateLV,
    const JET_SPACEHINTS * const    pSpacehintsLV,
    const ULONG                     cbLVChunkMax
    );

INLINE ERR ErrCATAddTable(
    PIB                             *ppib,
    const IFMP                      ifmp,
    const PGNO                      pgnoTableFDP,
    const OBJID                     objidTable,
    const CHAR                      *szTableName,
    const CHAR                      *szTemplateTableName,
    const ULONG                     ulFlags,
    const JET_SPACEHINTS * const    pSpacehints,
    const ULONG                     cbSeparateLV,
    const JET_SPACEHINTS * const    pSpacehintsLV,
    const ULONG                     cbLVChunkMax )
{
    ERR             err;
    FUCB            *pfucbCatalog;

    CallR( ErrCATOpen( ppib, ifmp, &pfucbCatalog ) );
    Assert( pfucbNil != pfucbCatalog );

    err = ErrCATAddTable(
                ppib,
                pfucbCatalog,
                pgnoTableFDP,
                objidTable,
                szTableName,
                szTemplateTableName,
                ulFlags,
                pSpacehints,
                cbSeparateLV,
                pSpacehintsLV,
                cbLVChunkMax );

    CallS( ErrCATClose( ppib, pfucbCatalog ) );

    return err;
}

ERR ErrCATAddTableColumn(
    PIB             *ppib,
    FUCB            *pfucbCatalog,
    const OBJID     objidTable,
    const CHAR      *szColumnName,
    COLUMNID        columnid,
    const FIELD     *pfield,
    const VOID      *pvDefault,
    const ULONG     cbDefault,
    const CHAR      * const szCallback,
    const VOID      * const pvUserData,
    const ULONG     cbUserData );
INLINE ERR ErrCATAddTableColumn(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szColumnName,
    const COLUMNID  columnid,
    const FIELD     *pfield,
    const VOID      *pvDefault,
    const ULONG     cbDefault,
    const CHAR      * const szCallback,
    const VOID      * const pvUserData,
    const ULONG     cbUserData )
{
    ERR             err;
    FUCB            *pfucbCatalog;

    CallR( ErrCATOpen( ppib, ifmp, &pfucbCatalog ) );
    Assert( pfucbNil != pfucbCatalog );

    err = ErrCATAddTableColumn(
                ppib,
                pfucbCatalog,
                objidTable,
                szColumnName,
                columnid,
                pfield,
                pvDefault,
                cbDefault,
                szCallback,
                pvUserData,
                cbUserData );

    CallS( ErrCATClose( ppib, pfucbCatalog ) );

    return err;
}


ERR ErrCATAddTableIndex(
    PIB                 *ppib,
    FUCB                *pfucbCatalog,
    const OBJID         objidTable,
    const CHAR          *szIndexName,
    const PGNO          pgnoIndexFDP,
    const OBJID         objidIndex,
    const IDB           *pidb,
    const IDXSEG* const rgidxseg,
    const IDXSEG* const rgidxsegConditional,
    const JET_SPACEHINTS * const pspacehints );

INLINE ERR ErrCATAddTableIndex(
    PIB                 *ppib,
    const IFMP          ifmp,
    const OBJID         objidTable,
    const CHAR          *szIndexName,
    const PGNO          pgnoIndexFDP,
    const OBJID         objidIndex,
    const IDB           *pidb,
    const IDXSEG* const rgidxseg,
    const IDXSEG* const rgidxsegConditional,
    const JET_SPACEHINTS * const pspacehints )
{
    ERR                 err;
    FUCB                *pfucbCatalog;

    CallR( ErrCATOpen( ppib, ifmp, &pfucbCatalog ) );
    Assert( pfucbNil != pfucbCatalog );

    err = ErrCATAddTableIndex(
                ppib,
                pfucbCatalog,
                objidTable,
                szIndexName,
                pgnoIndexFDP,
                objidIndex,
                pidb,
                rgidxseg,
                rgidxsegConditional,
                pspacehints );

    CallS( ErrCATClose( ppib, pfucbCatalog ) );

    return err;
}

ERR ErrCATIAddTableLV(
    PIB             *ppib,
    FUCB            *pfucbCatalog,
    const OBJID     objidTable,
    const PGNO      pgnoLVFDP,
    const OBJID     objidLV );
INLINE ERR ErrCATAddTableLV(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const PGNO      pgnoLVFDP,
    const OBJID     objidLV )
{
    ERR             err;
    FUCB            *pfucbCatalog;

    CallR( ErrCATOpen( ppib, ifmp, &pfucbCatalog ) );
    Assert( pfucbNil != pfucbCatalog );

    err = ErrCATIAddTableLV(
                ppib,
                pfucbCatalog,
                objidTable,
                pgnoLVFDP,
                objidLV );

    CallS( ErrCATClose( ppib, pfucbCatalog ) );

    return err;
}

ERR ErrCATCopyCallbacks(
    PIB * const ppib,
    const IFMP ifmpSrc,
    const IFMP ifmpDest,
    const OBJID objidSrc,
    const OBJID objidDest );

ERR ErrCATAddTableCallback(
    PIB                 *ppib,
    FUCB                *pfucbCatalog,
    const OBJID         objidTable,
    const JET_CBTYP     cbtyp,
    const CHAR * const  szCallback );
INLINE ERR ErrCATAddTableCallback(
    PIB                 *ppib,
    const IFMP          ifmp,
    const OBJID         objidTable,
    const JET_CBTYP     cbtyp,
    const CHAR * const  szCallback )
{
    ERR             err;
    FUCB            *pfucbCatalog;

    CallR( ErrCATOpen( ppib, ifmp, &pfucbCatalog ) );
    Assert( pfucbNil != pfucbCatalog );

    err = ErrCATAddTableCallback(
                ppib,
                pfucbCatalog,
                objidTable,
                cbtyp,
                szCallback );

    CallS( ErrCATClose( ppib, pfucbCatalog ) );

    return err;
}

ERR ErrCATSeekObjectByObjid(
    _In_ PIB* const     ppib,
    _In_ const IFMP     ifmp,
    _In_ const OBJID    objidTable,
    _In_ const SYSOBJ   sysobj,
    _In_ const OBJID    objid,
    _Out_writes_( cchName ) PSTR const szName,
    _In_ const INT      cchName,
    _Out_ PGNO* const   ppgnoFDP );

ERR ErrCATSeekTable(
    _In_ PIB                *ppib,
    _In_ const IFMP         ifmp,
    _In_z_ const CHAR       *szTableName,
    _Out_opt_ PGNO          *ppgnoTableFDP,
    _Out_opt_ OBJID         *pobjidTable = NULL );

ERR ErrCATSeekTableByObjid(
    IN PIB          * const ppib,
    IN const IFMP   ifmp,
    IN const OBJID  objidTable,
    __out_ecount_z( cchTableName ) PSTR const szTableName,
    IN const INT    cchTableName,
    OUT PGNO        * const ppgnoTableFDP );

ERR ErrCATGetObjidMetadata(
    _In_ PIB* const     ppib,
    _In_ const IFMP     ifmp,
    _In_ const OBJID    objid,
    _Out_ OBJID         *pobjidTable,
    _Out_ SYSOBJ        *psysobj );

ERR ErrCATGetNextRootObject(
    _In_ PIB* const         ppib,
    _In_ const IFMP         ifmp,
    _Inout_ FUCB** const    ppfucbCatalog,
    _Out_ OBJID* const      pobjid );

ERR ErrCATGetNextNonRootObject(
    _In_ PIB* const         ppib,
    _In_ const IFMP         ifmp,
    _In_ const OBJID        objidTable,
    _Inout_ FUCB** const    ppfucbCatalog,
    _Out_ OBJID* const      pobjid,
    _Out_ SYSOBJ* const     psysobj );

ERR ErrCATGetNextObjectByPgnoFDP(
    _In_ PIB* const         ppib,
    _In_ const IFMP         ifmp,
    _In_ const OBJID        objidTable,
    _In_ const PGNO         pgnoFDP,
    _In_ const BOOL         fShadow,
    _Inout_ FUCB** const    ppfucbCatalog,
    _Out_ OBJID* const      pobjid,
    _Out_ SYSOBJ* const     psysobj );

ERR ErrCATGetCursorsFromObjid(
    _In_ PIB* const ppib,
    _In_ const IFMP ifmp,
    _In_ const OBJID objid,
    _In_ const OBJID objidParent,
    _In_ const SYSOBJ sysobj,
    _Out_ PGNO* const ppgnoFDP,
    _Out_ PGNO* const ppgnoFDPParent,
    _Out_ FUCB** const ppfucb,
    _Out_ FUCB** const ppfucbParent );

VOID CATFreeCursorsFromObjid( _In_ FUCB* const pfucb, _In_ FUCB* const pfucbParent );

ERR ErrCATDeleteDbObject(
    PIB             * const ppib,
    const IFMP      ifmp,
    const CHAR      * const szName,
    const SYSOBJ    sysobj );
ERR ErrCATDeleteTable(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable );
ERR ErrCATDeleteTableColumn(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szColumnName,
    COLUMNID        *pcolumnid );
ERR ErrCATDeleteTableIndex(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szIndexName,
    PGNO            *ppgnoIndexFDP );

ERR ErrCATAccessTableColumn(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szColumnName,
    JET_COLUMNID    *pcolumnid = NULL,
    const BOOL      fLockTableColumn = fFalse );
ERR ErrCATAccessTableIndex(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const OBJID     objidIndex );
ERR ErrCATAccessTableLV(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    PGNO            *ppgnoLVFDP,
    OBJID           *pobjidLV = NULL );

ERR ErrCATGetTableInfoCursor(
    PIB             *ppib,
    const IFMP      ifmp,
    const CHAR      *szTableName,
    FUCB            **ppfucbInfo );

ERR ErrCATGetObjectNameFromObjid(
    PIB         *ppib,
    const IFMP  ifmp,
    const OBJID     objidTable,
    const SYSOBJ    sysobj,
    const OBJID objid,
    __out_bcount(cbName) PSTR       szName,
    ULONG       cbName );

ERR ErrCATGetTableAllocInfo(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    ULONG           *pulPages,
    ULONG           *pulDensity,
    PGNO            *ppgnoFDP = NULL);
ERR ErrCATGetIndexAllocInfo(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szIndexName,
    ULONG           *pulDensity );
ERR ErrCATGetIndexLcid(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szIndexName,
    LCID            *plcid );
ERR ErrCATGetIndexLocaleName(
    _In_ PIB            *ppib,
    _In_ const IFMP     ifmp,
    _In_ const OBJID    objidTable,
    _In_ const CHAR     *szIndexName,
    _Out_writes_bytes_( cbLocaleName ) PWSTR    wszLocaleName,
    _In_ ULONG          cbLocaleName );
ERR ErrCATGetIndexSortVersion(
    _In_ PIB            *ppib,
    _In_ const IFMP     ifmp,
    _In_ const OBJID    objidTable,
    _In_ const CHAR     *szIndexName,
    _Out_ DWORD         *pdwOutputSortVersion );
ERR ErrCATGetIndexDefinedSortVersion(
    _In_ PIB            *ppib,
    _In_ const IFMP     ifmp,
    _In_ const OBJID    objidTable,
    _In_ const CHAR     *szIndexName,
    _Out_ DWORD         *pdwOutputDefinedSortVersion );
ERR ErrCATGetIndexSortid(
    _In_ PIB            *ppib,
    _In_ const IFMP     ifmp,
    _In_ const OBJID    objidTable,
    _In_ const CHAR     *szIndexName,
    _Out_ SORTID        *psortid );
ERR ErrCATGetIndexVarSegMac(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szIndexName,
    USHORT          *pusVarSegMac );
ERR ErrCATGetIndexKeyMost(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const CHAR      *szIndexName,
    USHORT          *psKeyMost );
ERR ErrCATGetIndexSegments(
    PIB             *ppib,
    const IFMP      ifmp,
    const OBJID     objidTable,
    const IDXSEG*   rgidxseg,
    const ULONG     cidxseg,
    const BOOL      fConditional,
    const BOOL      fOldFormat,
    CHAR            rgszSegments[JET_ccolKeyMost][JET_cbNameMost+1+1] );

ERR ErrCATGetColumnCallbackInfo(
    PIB * const ppib,
    const IFMP ifmp,
    const OBJID objidTable,
    const OBJID objidTemplateTable,
    const COLUMNID columnid,
    __out_bcount_part(cchCallbackMax, *pchCallback) PSTR const szCallback,
    const ULONG cchCallbackMax,
    ULONG * const pchCallback,
    __out_bcount_part(cbUserDataMax, *pcbUserData) BYTE * const pbUserData,
    const ULONG cbUserDataMax,
    ULONG * const pcbUserData,
    __out_bcount_part(cchDependantColumnsMax, *pchDependantColumns) PSTR const szDependantColumns,
    const ULONG cchDependantColumnsMax,
    ULONG * const pchDependantColumns
    );

ERR ErrCATInitCatalogFCB( FUCB *pfucbTable );
ERR ErrCATInitTempFCB( FUCB *pfucbTable );
ERR ErrCATInitFCB( FUCB *pfucbTable, OBJID objidTable );

enum CATCheckIndicesFlags
{
    catcifReadOnly = 0x1,
    catcifDeleteOutOfDateSecondaryIndices = 0x2,
    catcifReportOnlyOutOfDateSecondaryIndices = 0x4,
    catcifUpdateEmptyIndices = 0X8,
    catcifForceDeleteIndices = 0x10,
    catcifAllowValidOutOfDateVersions = 0x20,
};

DEFINE_ENUM_FLAG_OPERATORS_BASIC( CATCheckIndicesFlags )

ERR ErrCATCheckLocalizedIndexesInTable(
    _In_ PIB        * const ppib,
    _In_ const IFMP ifmp,
    _In_ FCB        * const pfcbTable,
    _In_opt_ FUCB   * const pfucbTable,
    _In_z_ const CHAR   *szTableName,
    _In_ CATCheckIndicesFlags   catcifFlags,
    _Out_ BOOL      *pfIndexesUpdated,
    _Out_ BOOL      *pfIndicesDeleted );

ERR ErrCATChangePgnoFDP( PIB *ppib, IFMP ifmp, OBJID objidTable, OBJID objid, SYSOBJ sysobj, PGNO pgnoFDPNew );
ERR ErrCATChangeColumnDefaultValue(
    PIB         *ppib,
    const IFMP  ifmp,
    const OBJID objidTable,
    const CHAR  *szColumn,
    const DATA& dataDefault );

ERR ErrCATDeleteOrUpdateOutOfDateLocalizedIndexes(
        IN PIB * const ppib,
        IN const IFMP ifmp,
        IN CATCheckIndicesFlags catcifFlags,
        OUT BOOL * const pfIndexesUpdated,
        OUT BOOL * const pfIndexesDeleted);

ERR ErrCATRenameTable(
    PIB         * const ppib,
    const IFMP          ifmp,
    const CHAR * const szNameOld,
    const CHAR * const szNameNew );

ERR ErrCATRenameColumn(
    PIB             * const ppib,
    const FUCB      * const pfucbTable,
    const CHAR      * const szNameOld,
    const CHAR      * const szNameNew,
    const JET_GRBIT grbit );

ULONG UlCATColumnSize(
    JET_COLTYP      coltyp,
    INT             cbMax,
    BOOL            *pfMaxTruncated );

ERR ErrCATAddCallbackToTable(
    PIB * const ppib,
    const IFMP ifmp,
    const CHAR * const szTable,
    const JET_CBTYP cbtyp,
    const CHAR * const szCallback );

ERR ErrCATAddColumnCallback(
    PIB * const ppib,
    const IFMP ifmp,
    const CHAR * const szTable,
    const CHAR * const szColumn,
    const CHAR * const szCallback,
    const VOID * const pvCallbackData,
    const ULONG cbCallbackData
    );

ERR ErrCATConvertColumn(
    PIB * const ppib,
    const IFMP ifmp,
    const CHAR * const szTable,
    const CHAR * const szColumn,
    const JET_COLTYP coltyp,
    const JET_GRBIT grbit );

ERR ErrCATIncreaseMaxColumnSize(
    PIB * const         ppib,
    const IFMP          ifmp,
    const CHAR * const  szTable,
    const CHAR * const  szColumn,
    const ULONG         cbMaxLen );

ERR ErrCATAddConditionalColumnsToAllIndexes(
    PIB * const ppib,
    const IFMP ifmp,
    const CHAR * const szTable,
    const JET_CONDITIONALCOLUMN_A * rgconditionalcolumn,
    const ULONG cConditionalColumn );

ERR ErrCATChangeIndexDensity(
    PIB * const         ppib,
    const IFMP          ifmp,
    const CHAR * const  szTable,
    const CHAR * const  szIndex,
    const ULONG         ulDensity );

ERR ErrCATChangeIndexFlags(
    PIB * const         ppib,
    const IFMP          ifmp,
    const OBJID         objidTable,
    const CHAR * const  szIndex,
    const IDBFLAG       idbflagNew,
    const IDXFLAG       idxflagNew );

ERR ErrCATChangeCallbackDLL(
    PIB * const         ppib,
    const IFMP          ifmp,
    const CHAR * const  szOldDLL,
    const CHAR * const  szNewDLL );

ERR ErrCATInit();
void CATTerm();



INLINE UINT UiHashIfmpName( IFMP ifmp, const CHAR* const szName )
{
    Assert( NULL != szName );

    UINT            uiHash  = 0;
    SIZE_T          ib      = 0;
    const SIZE_T    cb      = strlen( szName );

    switch( cb % 8 )
    {
        case 0:
        while ( ib < cb )
        {
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 7:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 6:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 5:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 4:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 3:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 2:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        case 1:
            uiHash = ( _rotl( uiHash, 6 ) + (BYTE)ChUtilNormChar( szName[ib++] ) );
        }
    }

    return UINT( ifmp + cb + uiHash );
}



class CATHashKey
{
    public:

        CATHashKey()
        {
        }

        CATHashKey( IFMP ifmpIn, __in PCSTR const szNameIn )
        {
            m_uiHashIfmpName = UiHashIfmpName( ifmpIn, szNameIn );
            m_ifmp = ifmpIn;
            Assert( szNameIn );
            m_pszName = szNameIn;
        }

        CATHashKey( const CATHashKey &src )
        {
            *this = src;
        }

        const CATHashKey &operator =( const CATHashKey &src )
        {
            Assert( UiHashIfmpName( src.m_ifmp, src.m_pszName ) == src.m_uiHashIfmpName );
            m_uiHashIfmpName = src.m_uiHashIfmpName;
            m_ifmp = src.m_ifmp;
            m_pszName = src.m_pszName;

            return *this;
        }

    public:

        UINT    m_uiHashIfmpName;
        IFMP    m_ifmp;
        PCSTR   m_pszName;
};



class CATHashEntry
{
    public:

        CATHashEntry()
        {
        }

        CATHashEntry( const CATHashEntry &src )
        {
            *this = src;
        }

        CATHashEntry( FCB *pfcbIn )
            :   m_pfcb( pfcbIn )
        {
            Assert( pfcbNil != pfcbIn );
            Assert( ptdbNil != pfcbIn->Ptdb() );
            pfcbIn->EnterDML();
            m_uiHashIfmpName = UiHashIfmpName( pfcbIn->Ifmp(), pfcbIn->Ptdb()->SzTableName() );
#ifdef DEBUG
            m_pgnoFDPDBG = pfcbIn->PgnoFDP();
            m_objidFDPDBG = pfcbIn->ObjidFDP();
            m_ifmpDBG = pfcbIn->Ifmp();
            OSStrCbCopyA( m_szNameDBG, sizeof( m_szNameDBG ), pfcbIn->Ptdb()->SzTableName() );
#endif
            pfcbIn->LeaveDML();
        }

        const CATHashEntry &operator =( const CATHashEntry &src )
        {
            m_uiHashIfmpName = src.m_uiHashIfmpName;
            m_pfcb = src.m_pfcb;
#ifdef DEBUG
            m_pgnoFDPDBG = src.m_pgnoFDPDBG;
            m_objidFDPDBG = src.m_objidFDPDBG;
            m_ifmpDBG = src.m_ifmpDBG;
            OSStrCbCopyA( m_szNameDBG, sizeof( m_szNameDBG ), src.m_szNameDBG );
#endif

            return *this;
        }

    public:

        UINT    m_uiHashIfmpName;
        FCB     *m_pfcb;
#ifdef DEBUG
        PGNO    m_pgnoFDPDBG;
        OBJID   m_objidFDPDBG;
        IFMP    m_ifmpDBG;
        CHAR    m_szNameDBG[JET_cbNameMost+1];
#endif
};



typedef CDynamicHashTable< CATHashKey, CATHashEntry > CATHash;

INLINE CATHash::NativeCounter CATHash::CKeyEntry::Hash( const CATHashKey &key )
{
    Assert( key.m_uiHashIfmpName == UiHashIfmpName( key.m_ifmp, key.m_pszName ) );
    return CATHash::NativeCounter( key.m_uiHashIfmpName );
}

INLINE CATHash::NativeCounter CATHash::CKeyEntry::Hash() const
{
    Assert( pfcbNil != m_entry.m_pfcb );
    Assert( ptdbNil != m_entry.m_pfcb->Ptdb() );
#ifdef DEBUG
    m_entry.m_pfcb->EnterDML();
    Assert( m_entry.m_uiHashIfmpName == UiHashIfmpName( m_entry.m_pfcb->Ifmp(), m_entry.m_pfcb->Ptdb()->SzTableName() ) );
    m_entry.m_pfcb->LeaveDML();
#endif
    return CATHash::NativeCounter( m_entry.m_uiHashIfmpName );
}

INLINE BOOL CATHash::CKeyEntry::FEntryMatchesKey( const CATHashKey &key ) const
{
    Assert( key.m_uiHashIfmpName == UiHashIfmpName( key.m_ifmp, key.m_pszName ) );
    Assert( pfcbNil != m_entry.m_pfcb );
    Assert( ptdbNil != m_entry.m_pfcb->Ptdb() );


    if ( m_entry.m_uiHashIfmpName == key.m_uiHashIfmpName && m_entry.m_pfcb->Ifmp() == key.m_ifmp )
    {
        m_entry.m_pfcb->EnterDML();
        Assert( m_entry.m_uiHashIfmpName == UiHashIfmpName( m_entry.m_pfcb->Ifmp(), m_entry.m_pfcb->Ptdb()->SzTableName() ) );
        const BOOL fMatch = UtilCmpName( m_entry.m_pfcb->Ptdb()->SzTableName(), key.m_pszName ) == 0;
        m_entry.m_pfcb->LeaveDML();
        return fMatch;
    }
    return fFalse;
}

INLINE void CATHash::CKeyEntry::SetEntry( const CATHashEntry &src )
{
    m_entry = src;
}

INLINE void CATHash::CKeyEntry::GetEntry( CATHashEntry * const pdst ) const
{
    *pdst = m_entry;
}

extern CATHash g_cathash;




#ifdef DEBUG


VOID CATHashAssertCleanIfmpPgnoFDP( const IFMP ifmp, const PGNO pgnoFDP );


VOID CATHashAssertCleanIfmp( const IFMP ifmp );


VOID CATHashAssertClean();

#endif



BOOL FCATHashILookup(
    IFMP            ifmp,
    __in PCSTR const    szTableName,
    PGNO            *ppgnoTableFDP,
    OBJID           *pobjidTable );


VOID CATHashIInsert( FCB *pfcb, __in PCSTR const szTable );


VOID CATHashIDelete( FCB *pfcb, __in PCSTR const szTable );



INLINE BOOL FCATHashActive( INST *pinst )
{


    return  !pinst->FRecovering() &&
            !pinst->m_plog->FHardRestore() &&
            !g_fRepair;
}



INLINE BOOL FCATHashLookup(
    IFMP            ifmp,
    __in PCSTR const    szTableName,
    PGNO* const     ppgnoTableFDP,
    OBJID* const    pobjidTable )
{
    Assert( NULL != ppgnoTableFDP );
    Assert( NULL != pobjidTable );

    return ( FCATHashActive( PinstFromIfmp( ifmp ) ) ?
                    FCATHashILookup( ifmp, szTableName, ppgnoTableFDP, pobjidTable ) :
                    fFalse );
}



INLINE VOID CATHashInsert( FCB *pfcb, __in PCSTR const szTable )
{
    Assert( pfcbNil != pfcb );
    Assert( ptdbNil != pfcb->Ptdb() );

    if ( FCATHashActive( PinstFromIfmp( pfcb->Ifmp() ) ) )
    {
        CATHashIInsert( pfcb, szTable );
    }
}



INLINE VOID CATHashDelete( FCB *pfcb, __in PCSTR const szTable )
{
    Assert( pfcbNil != pfcb );
    Assert( ptdbNil != pfcb->Ptdb() );

    if ( FCATHashActive( PinstFromIfmp( pfcb->Ifmp() ) ) )
    {
        CATHashIDelete( pfcb, szTable );
    }
}

ERR ErrCATDeleteMSU(
        IN PIB * const ppib,
        IN const IFMP ifmp );

ERR ErrCATCheckMSObjidsReady(
        __in PIB * const ppib,
        const IFMP ifmp,
        __out BOOL * const pfReady );

ERR ErrCATCreateMSObjids(
        __in PIB * const ppib,
        const IFMP ifmp );

ERR ErrCATDeleteMSObjids(
        _In_ PIB * const ppib,
        _In_ const IFMP ifmp );

ERR ErrCATPopulateMSObjids(
        __in PIB * const ppib,
        const IFMP ifmp );

ERR ErrCATInsertMSObjidsRecord(
        __in PIB * const ppib,
        const IFMP ifmp,
        const OBJID objid,
        const OBJID objidTable,
        const SYSOBJ sysobj );

ERR ErrCATMSObjidsRecordExists(
        __in PIB * const ppib,
        const IFMP ifmp,
        const OBJID objid,
        __out bool * const pfExists );

ERR ErrCATDeleteMSObjidsRecord(
        __in PIB * const ppib,
        const IFMP ifmp,
        const OBJID objid );

ERR ErrCATPossiblyDeleteMSObjidsRecord(
        __in PIB * const ppib,
        FUCB * const pfucbCatalog );

ERR ErrCATVerifyMSObjids(
        __in PIB * const ppib,
        const IFMP ifmp,
              CPRINTF * const pcprintfError );

ERR ErrCATCreateMSLocales(
        __in PIB * const ppib,
        const IFMP ifmp );

ERR ErrCATCreateOrUpgradeMSLocales(
        __in PIB * const ppib,
        const IFMP ifmp );

ERR ErrCATDeleteMSLocales(
        __in PIB * const ppib,
        __in const IFMP ifmp );

VOID CATTermMSLocales(
        FMP * const pfmp );

ERR ErrCATCheckForOutOfDateLocales(
        const IFMP ifmp,
        __out BOOL * const pfOutOfDateNLSVersion );

ERR ErrCATVerifyMSLocales(
    __in PIB * const ppib,
    __in const IFMP ifmp,
    __in const BOOL fFixupMSysLocales );

ERR ErrCATDumpMSLocales(
        JET_SESID sesid,
        const IFMP ifmp );

ERR ErrCATIAddLocale(
    _In_ PIB * const ppib,
    _In_ const IFMP ifmp,
    _In_ PCWSTR wszLocaleName,
    _In_ SORTID sortID,
    _In_ const QWORD qwSortVersion );

ERR ErrCATScanTableIndices(
    _In_ PIB * const ppib,
    _In_ FUCB * const pfucbCatalog,
    _In_ OBJID  objidTable,
    _In_ ERR (* pcallback) (VOID * const, char *),
    _In_ VOID * pvparam );

ERR ErrCATISeekTableType(
    _In_ PIB            *ppib,
    _In_ FUCB           *pfucbCatalog,
    _In_ const OBJID    objidTable,
    _In_ const OBJID    objidFDP,
    _Out_ SYSOBJ        *psysobjType,
    _Out_writes_z_( cbIndex ) CHAR  *szIndex,
    _In_ const ULONG    cbIndex );


#define PERSISTED_SORTID_MAX_LENGTH 37

INLINE VOID WszCATFormatSortID(
    __in const SORTID & sortID,
    __out_ecount( cch ) WCHAR * wsz,
    __in INT cch );

